#This file is part of SciPAL.

#    SciPAL is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    SciPAL is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.

#    You should have received a copy of the GNU Lesser General Public License
#    along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.

#Copyright  S. C. Kramer , J. Hagemann  2010 - 2014

# Moving an existing step-xy project 
# author : Stephan Kramer, 7.3.2013,
# Institut fuer Numerische und Angewandte Mathematik, U Goettingen 

#from glob import iglob
from glob import glob
import shutil
import os
import sys




def find_root_dir():
    print "start cwd : " + os.getcwd() 	
    while str(os.path.split(os.getcwd())[1]) != "Praktikum_2013":
        os.chdir("..")
        print "cwd : " + os.getcwd()
    os.chdir("testsite")
    print "cwd : " + os.getcwd()




def copy_no_svn(old_number, new_number):

    old_step = "step-%d" % int(old_number)
    new_step = "step-%d" % int(new_number)

    print "Start cwd : " + os.getcwd()
    if os.path.exists(new_step):
        print "%s already exists" % new_step
        return False
    else:
        shutil.copytree(old_step, new_step)
        return True


def move_svn(old_number, new_number):

    old_step = "step-%d" % int(old_number)
    new_step = "step-%d" % int(new_number)

    print "Start cwd : " + os.getcwd()
    if os.path.exists(new_step):
        print "%s already exists" % new_step
        return False
    else:
        # clean up
        if os.path.exists("step-" + str(old_number) + ".pro.user"):
            os.remove("step-" + str(old_number) + ".pro.user")

        # start the move
        os.system("svn move %s %s"% (old_step, new_step) )  #shutil.copytree(old_step, new_step)
        os.system("svn commit -m\"step renamed\" %s %s" % (old_step, new_step) )

        os.chdir(new_step)
        print "Start : " + os.getcwd()
        template_files = glob("*"+old_step+"*.*")

        for f in template_files:
            os.system("svn move %s %s"% (f, f.replace(str(old_number), str(new_number))) )
        os.system("svn commit -m\"step files renamed\" " )
        return True



def copy_template(old_number, new_number):

    old_step = "step-%d" % int(old_number)
    new_step = "step-%d" % int(new_number)

    os.chdir(new_step)
    # in case of svn : template_files = glob("*"+new_step+"*.*")
    # without svn : 
    template_files = []
    template_files.append( glob("*.h") )
    template_files.append( glob("*.hh") )
    template_files.append( glob("*.c") ) 
    template_files.append( glob("*.pro*") ) 
    template_files.append( glob("*.cu") )
    template_files.append( glob("*.cpp") )
    template_files.append( glob("prm/*.prm") )
    template_files.append(glob("doxygen_filelist"))
    print "files to modify : "
    for ll in template_files:
        for f in ll:
            print str(f)
            file = open(f,'r')
            lines = file.readlines()
            file.close()
            # Replace names of namespaces, etc ...
            file = open(f,'w')
            for line in lines:
                if line.find("step%d" % old_number) > 1:
                    tmpl = line.replace("step%d" % old_number, "step%d" % new_number)
                    line = tmpl
                if line.startswith("step%d" % old_number):
                    tmpl = line.replace("step%d" % old_number, "step%d" % new_number)
                    line = tmpl
                if line.find("step-%d" % old_number) > 1:
                    tmpl = line.replace("step-%d" % old_number, "step-%d" % new_number)
                    line = tmpl
                if line.startswith("step-%d" % old_number):
                    tmpl = line.replace("step-%d" % old_number, "step-%d" % new_number)
                    line = tmpl
                if line.find("step_%d" % old_number) > 1:
                    tmpl = line.replace("step_%d" % old_number, "step_%d" % new_number)
                    line = tmpl
                if line.find("STEP_%d" % old_number) > 1:
                    tmpl = line.replace("STEP_%d" % old_number, "STEP_%d" % new_number)
                    line = tmpl
                file.write(line)
            file.close()
            os.system("mv %s %s"% (f, f.replace(str(old_number), str(new_number))) )
        
        
    #os.system("svn commit -m\"renaming step files completed\" " )

    print "Done : " + os.getcwd()
    os.chdir("..")



############ MAIN ###############################

def my_main():
    if (len(sys.argv) != 3):
        print "Usage : " + str(sys.argv[0]) + " <from number> <to number>"
        print "<from number> : old step number"
        print "<to number>   : new step number"
        return

    old_number = sys.argv[1]
    new_number = sys.argv[2]

    if (old_number.isdigit() != True or new_number.isdigit() != True):
        print "invalid inputs"
        return

    find_root_dir()

    do_copy = copy_no_svn(int(old_number), int(new_number) )

    if (do_copy):
        copy_template(int(old_number), int(new_number) )

my_main()
