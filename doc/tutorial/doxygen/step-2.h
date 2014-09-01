/**
 * @page step_2                 The step-2 tutorial program
@htmlonly
<table class="tutorial" width="100%">
<tr><th colspan="2"><b><small>Table of contents</small></b></th></tr>
<tr><td width="50%" valign="top">
<ol>
  <li> <a href="#Intro" class=bold>Introduction</a>
    <ul>
      </ul>
  <li> <a href="#CommProg" class=bold>The commented program</a>
    <ul>
      <ul>
        <li><a href="#Functionmain">Function: main</a>
      </ul>
        <li><a href="#ClassMyFancySimulation">Class: MyFancySimulation</a>
      <ul>
        <li><a href="#ConstructorMyFancySimulation">Constructor: MyFancySimulation</a>
        <li><a href="#Functionrun">Function: run</a>
        <li><a href="#Functionsave_results">Function: save_results</a>
      </ul>
        <li><a href="#EnumMVCase">Enum: MVCase</a>
        <li><a href="#structSimUIParams">struct: SimUIParams</a>
        <li><a href="#ClassTestUIParamsBase">Class: TestUIParamsBase</a>
        <li><a href="#ClassMVTestUIParams">Class: MVTestUIParams</a>
        <li><a href="#ClassMVTest">Class: MVTest</a>
      <ul>
        <li><a href="#Constructor">Constructor</a>
        <li><a href="#Destructor">Destructor</a>
        <li><a href="#Functionrun">Function: run</a>
        <li><a href="#Functionsetup_and_assemble">Function: setup_and_assemble</a>
      </ul>
        <li><a href="#ClassMVMultDriverInterface">Class: MVMultDriverInterface</a>
      <ul>
        <li><a href="#Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#ClassCpuBlasDriver">Class: CpuBlasDriver</a>
      <ul>
        <li><a href="#Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#ClassCUBlasDriver">Class: CUBlasDriver</a>
      <ul>
        <li><a href="#ConstructorCUBlasDriver">Constructor: CUBlasDriver</a>
        <li><a href="#DestructorCUBlasDriver">Destructor: CUBlasDriver</a>
        <li><a href="#Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#ClassFujimotoDriver">Class: FujimotoDriver</a>
      <ul>
        <li><a href="#Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#DeclarationofCUDAInterface">Declaration of CUDA Interface</a>
        <li><a href="#ClassKernels">Class: Kernels</a>
        <li><a href="#Kernels">Kernels</a>
      <ul>
        <li><a href="#Kernel_mv_fujimoto">Kernel: _mv_fujimoto</a>
        <li><a href="#Kernel_mv_fujimoto_T">Kernel: _mv_fujimoto_T</a>
        <li><a href="#Kernel_mv_fujimoto_T2">Kernel: _mv_fujimoto_T2</a>
        <li><a href="#Kernel_mv_fujimoto_T3">Kernel: _mv_fujimoto_T3</a>
        <li><a href="#Functionmv_fujimoto">Function: mv_fujimoto</a>
      </ul>
      </ul>
</ol></td><td width="50%" valign="top"><ol>
  <li value="3"> <a href="#Results" class=bold>Results</a>
    <ul>
        <li><a href="#Plots">Plots</a>
      </ul>
  <li> <a href="#PlainProg" class=bold>The plain program</a>
    <ul>
      <ul>
        <li><a href="#plain-Functionmain">Function: main</a>
      </ul>
        <li><a href="#plain-ClassMyFancySimulation">Class: MyFancySimulation</a>
      <ul>
        <li><a href="#plain-ConstructorMyFancySimulation">Constructor: MyFancySimulation</a>
        <li><a href="#plain-Functionrun">Function: run</a>
        <li><a href="#plain-Functionsave_results">Function: save_results</a>
      </ul>
        <li><a href="#plain-EnumMVCase">Enum: MVCase</a>
        <li><a href="#plain-structSimUIParams">struct: SimUIParams</a>
        <li><a href="#plain-ClassTestUIParamsBase">Class: TestUIParamsBase</a>
        <li><a href="#plain-ClassMVTestUIParams">Class: MVTestUIParams</a>
        <li><a href="#plain-ClassMVTest">Class: MVTest</a>
      <ul>
        <li><a href="#plain-Constructor">Constructor</a>
        <li><a href="#plain-Destructor">Destructor</a>
        <li><a href="#plain-Functionrun">Function: run</a>
        <li><a href="#plain-Functionsetup_and_assemble">Function: setup_and_assemble</a>
      </ul>
        <li><a href="#plain-ClassMVMultDriverInterface">Class: MVMultDriverInterface</a>
      <ul>
        <li><a href="#plain-Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#plain-ClassCpuBlasDriver">Class: CpuBlasDriver</a>
      <ul>
        <li><a href="#plain-Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#plain-ClassCUBlasDriver">Class: CUBlasDriver</a>
      <ul>
        <li><a href="#plain-ConstructorCUBlasDriver">Constructor: CUBlasDriver</a>
        <li><a href="#plain-DestructorCUBlasDriver">Destructor: CUBlasDriver</a>
        <li><a href="#plain-Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#plain-ClassFujimotoDriver">Class: FujimotoDriver</a>
      <ul>
        <li><a href="#plain-Functionmvmult">Function: mvmult</a>
      </ul>
        <li><a href="#plain-DeclarationofCUDAInterface">Declaration of CUDA Interface</a>
        <li><a href="#plain-ClassKernels">Class: Kernels</a>
        <li><a href="#plain-Kernels">Kernels</a>
      <ul>
        <li><a href="#plain-Kernel_mv_fujimoto">Kernel: _mv_fujimoto</a>
        <li><a href="#plain-Kernel_mv_fujimoto_T">Kernel: _mv_fujimoto_T</a>
        <li><a href="#plain-Kernel_mv_fujimoto_T2">Kernel: _mv_fujimoto_T2</a>
        <li><a href="#plain-Kernel_mv_fujimoto_T3">Kernel: _mv_fujimoto_T3</a>
        <li><a href="#plain-Functionmv_fujimoto">Function: mv_fujimoto</a>
      </ul>
      </ul>
</ol> </td> </tr> </table>
@endhtmlonly
<a name="Introduction"></a><h1>Introduction</h1>


<a name="Overview"></a><h2> Overview </h2>

A fundamental operation in scientific computing is the multiplication of a dense matrix with a dense vector.
This program compares the performance of different implementations of this product using different hardware.
A parallelized CPU version and two different CUDA implementations are benchmarked against each other.
The results of running this program are two diagrams containing the runtimes of the different implementations
and the speedup of the CUDA variants over the CPU-based version over a wide range of matrix sizes.
<p>
On the CPU we use the gemv fcuntino from ATLAS which is an open-source implementation of
BLAS available on virtually any standard Linux installation.
On the GPU we use gemv from CUDA's CUBLAS and Fujmoto's texture-based CUDA implementation of a matrix-vector product.
</p>
<p>
The mathematical operation itself is rather straightforward. Thus, this program rather addresses several
issues of practical importance:
<ul>
<li>The deal.II's ParameterHandler class is employed in order to feed the program with information at runtime, e.g.
for which matrix sizes the tests should be performed </li>
<li> The directory from where the program is launched is separated
from the directory where the results are to be stored. To do this, several QT classes are used.
</li>
<li> Object-orientation is employed to create an extensible framework for
unit testing of matrix-vector multiplications and similar operations.
</li>
<li> To minimize the amount of source code template classes are used to
implement the tests for the different BLAS versions independent of the particular number type.
For each BLAS library there is only one class.
By template specialization we get for each combination of BLAS and number type the appropriate implementation
which can be chosen at runtime by letting them all derive from a common base class.
</li>
<li>
We plot the graphs for the runtimes and speedups from within the program using a gnuplot pipe.
This frees us from the problem to figure out which columns have to be plotted versus each other and what to put into the legend.
The necessary gnuplot commands are collected in a file so that we can polish the figures still a bit
if the default values for e.g. the plot range do not give satisfactory results.
</li>
</ul>
</p> 


<p>
Before we study the program in detail let us still comment on why Fujimoto's implementation of a matrix-vector multiplication
is still of interest.
</p>
<p>
 Back in 2008 the only memory in CUDA-enabled GPUs with integrated caching capabilities was the
 texture memory.
 However, it during the executino of a CUDA kernel it was limited to read-only caching and updates to the texture
 became visible only after a relaunch of a kernel.
 The shared memory basically worked like a cache but had to be managed manually.
 The Fermi architecture introduced a two-level cache hierarchy which buffered all accesses to the global memory
 so that there was no direct access from the multiprocessors to the global memory anymore.
 However, there was still only one central texture cache which buffered the texture fetches
 issued by the different multiprocessors.
 With the Kepler architecture each multiprocessor got its own texture cache which had the same size
 of 64KB as the central one in the former architectures.
 A nice feature of the texture cache, then and now, is that it is optimized for data accesses of 2D spatial locality.
 Thus reading a matrix not in an element-per-element manner but en block by subdividing it into tiles and reading each tile
 as a whole should profit from this special feature of the texture cache.
 <br />
 This is the crucial idea of Fujimoto's method.
 </p>
 <p>
 Although the pay-off of this strategy should have decreased over the past due to the introduction of an "official" cache
 it is instructive to figure out whether it still is worth the effort today.
</p>


<a name="Literature"></a><h2> Literature </h2>


<ul>
<li> Fujimoto's article from 2008: Faster Matrix-Vector Multiplication on GeForce 8800GTX,
 In the Proceedings of the 22nd IEEE International Parallel and
 Distributed Processing Symposium (IPDPS), LSPP-402, pp.1-8, April 2008
</li>
<li> CUBLAS Reference
</li>
<li> Josuttis' book about C++ templates
</li>
<li> (More) Effective C++ by Scott Meyers
</li>
</ul>
 * <a name="CommProg"></a>
 * <h1> The commented program</h1>
 * 
 * 
 * @code
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #include <step-2/step-2.hh>
 * 
 * @endcode
 * 
 * 
 * <a name="Functionmain"></a> 
 * <h4>Function: main</h4>
 * 
 * 
 * As usual, the main function is pretty boring.
 * 
 * @code
 * int main(int argc, char *argv[])
 * {
 *     step2::MyFancySimulation sim(argc, argv);
 * 
 *     sim.run();
 * }
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef STEP_2_HH
 * #define STEP_2_HH
 * #include <cstdio>
 * @endcode
 * 
 * We walk through the program top-down starting with the file which contains the main() function.
 * 
 * 
 * We need several headers. First of all
 * STL's vector class.
 * 
 * @code
 * #include <vector>
 * 
 * @endcode
 * 
 * To store the measured runtimes in a table we use
 * deal.II's
 * 
 * @code
 * #include <deal.II/base/convergence_table.h>
 * 
 * @endcode
 * 
 * The basis for all CUDA-related programs is provided by the CUDA runtime library.
 * 
 * @code
 * #include <cuda_runtime.h>
 * @endcode
 * 
 * Our SciPAL library provides a little helper class which offers a more comfortable interface
 * to the technical data about the available GPUs.
 * 
 * @code
 * #include <../SciPAL/include/base/GPUInfo.h>
 * 
 * @endcode
 * 
 * Finally, one of the greatest aids in all the less-scientific issues in a program is QT's string class
 * 
 * @code
 * #include <QString>
 * 
 * @endcode
 * 
 * Last but not least, we need
 * the headers for the matrix-vector benchmark test
 * 
 * @code
 * #include <step-2/MVTest.h>
 * #include <step-2/MVTest.hh>
 * 
 * @endcode
 * 
 * and for the user interface.
 * 
 * @code
 * #include <step-2/MVTestUIParams.h>
 * 
 * @endcode
 * 
 * We encapsulate the whole project into a dedicated namespace
 * in order to be able to re-use
 * parts of this program in others.
 * 
 * @code
 * namespace step2 {
 * 
 * @endcode
 * 
 * 
 * <a name="ClassMyFancySimulation"></a> 
 * <h3>Class: MyFancySimulation</h3>
 * 
 * 
 * To make this test facility extendible, we implement
 * a class for a simple user interface. Its primary tasks are:
 * - Management of run-time parameters by a simple text-based parameter file.
 * - Setting device parameters according to the user's parameters.
 * - Preprocessing and output of results.
 * The result of this program is a comparison of the performance of different
 * implementations of the matrix-vector product for dense matrices and vectors.
 * The runtimes are collected in a central table @p results_table. It is an instance
 * of the dealii::ConvergenceTable class which has such nice member functions
 * like @p write_tex() which writes the contents to a tex file such that it can be
 * directly included in the tex source of an article.
 * <br />
 * The non-public part of this class is declared only as protected and not as private
 * in order to be able to reuse this class in other projects doing similar benchmark tests.
 * This is also the reason why the two main functions of this class are declared as <i>virtual</i>.
 * 
 * @code
 * class MyFancySimulation {
 * 
 * public:
 *    MyFancySimulation(int argc, char *argv[]);
 * 
 *    virtual void run();
 * 
 * protected:
 *     virtual void save_results();
 * 
 * 
 *     dealii::ConvergenceTable results_table;
 * 
 *     MVTestUIParams params;
 * 
 *     SciPAL::GPUInfo gpu_info;
 * 
 *     QString launch_dir;
 * 
 *     QString prm_dir;
 * 
 *     QString prm_log_dir;
 * };
 * 
 * }
 * 
 * @endcode
 * 
 * 
 * <a name="ConstructorMyFancySimulation"></a> 
 * <h4>Constructor: MyFancySimulation</h4>
 * 
 * 
 * The constructor is responsible for reading parameters
 * and initializing the device, i.e. the selected graphics card.
 * 
 * @code
 * step2::MyFancySimulation::MyFancySimulation(int argc, char *argv[])
 * {
 * @endcode
 * 
 * Before setting up the simulation we
 * figure out how many GPUs are available.
 * 
 * @code
 *     cudaGetDeviceCount(&gpu_info.n_CUDA_devices);
 *     std::cout
 *             << "N available CUDA devices : "
 *             << gpu_info.n_CUDA_devices << std::endl;
 * 
 *     gpu_info.get();
 * 
 * @endcode
 * 
 * Then, we declare and read parameters from a file. Basically, the parameter
 * file must have the same name as the binary. The extension has
 * to be ".prm". What has been read will be dumped into a log file.
 * We could use the parameter file to read a device ID and once the parameters
 * are read we could reset the @p gpu_info object to the new device.
 * 
 * @code
 *     dealii::ParameterHandler prm_handler;
 * 
 *     MVTestUIParams::declare(prm_handler);
 * 
 * @endcode
 * 
 * Before reading the parameters we set up the directories needed
 * during the execution of the program.
 * As point of reference we use directory where the program has been started.
 * 
 * @code
 *      QDir cwd = QDir::current();
 *      cwd.makeAbsolute();
 * 
 * @endcode
 * 
 * This is also the current working directory.
 * 
 * @code
 *    this->launch_dir = cwd.absolutePath();
 * 
 * @endcode
 * 
 * By default, the parameter file has the same name as the binary
 * and is supposed to be in a subdirectory prm of that directory
 * where the program has been started.
 * 
 * @code
 *     std::string prm_filename;
 * 
 *     if (argc == 1)
 *     {
 *         QFileInfo tmp(argv[0]);
 *         this->prm_dir = tmp.absolutePath() + "/prm";
 *         prm_filename  = tmp.fileName().toStdString();
 *         prm_filename += ".prm";
 *     }
 *     else
 *     {
 * @endcode
 * 
 * Whatever gets passed as first command line argument is considered as path
 * to a parameter file.
 * 
 * @code
 *         std::cout << "Given parameter file : " << argv[1] << std::endl;
 * 
 * @endcode
 * 
 * We convert the sequence of characters into something more meaningful.
 * 
 * @code
 *         QFileInfo tmp(argv[1]);
 * 
 * @endcode
 * 
 * Before we proceed, let us figure out whether the given parameter file exists.
 * Note: If the file is a symlink that points to a non existing file,
 * false is returned as well.
 * 
 * @code
 *         if(!tmp.exists())
 *         {
 *             std::cerr << "The following parameter file does not exist:\n"
 *                       << argv[1] << std::endl;
 * 
 *             qFatal("Cannot proceed without proper path to parameter file");
 *         }
 * 
 * @endcode
 * 
 * Next, we subdivide the given filename into its path and name
 * so that the corresponding subdirectories can be created.
 * 
 * @code
 *         this->prm_dir = tmp.absolutePath();
 * 
 *         prm_filename = tmp.fileName().toStdString();
 * 
 *         std::cout << "xx Parameter file path : "
 *                   << tmp.absolutePath().toStdString().c_str()
 *                   << std::endl;
 *     }
 * 
 * @endcode
 * 
 * For control purposes it is useful to notify the user of which parameter file has been actually used.
 * 
 * @code
 *     std::cout << "Parameter file : " << prm_filename  << std::endl;
 * 
 * @endcode
 * 
 * Before the parameter file can be read, we have to make sure that
 * its directory exists. In case of the default parameter file
 * the directory will be created.
 * 
 * @code
 *     cwd.mkpath(this->prm_dir);
 * 
 *     std::cout << "step-2: prm path : " << this->prm_dir.toStdString().c_str()  << std::endl;
 * 
 *     QDir::setCurrent(this->prm_dir);
 * 
 *     prm_handler.read_input (prm_filename);
 * 
 *     this->params.get(prm_handler);
 * 
 * @endcode
 * 
 * Having read the parameters we can create the toplevel run directory which was given in the parameter file.
 * 
 * @code
 *     QDir::setCurrent(this->launch_dir);
 *     cwd.mkpath(this->params.run_dir);
 *     QDir::setCurrent(this->params.run_dir);
 *     cwd = QDir::current();
 *     this->params.run_dir = cwd.absolutePath();
 * 
 *     std::cout << "Entering run dir : " << this->params.run_dir.toStdString().c_str()  << std::endl;
 * 
 * 
 * 
 * @endcode
 * 
 * Create the log directory and write what has been actually read
 * into a log file. Basically, this is just another parameter file
 * and thus can be used again as input to another run after stripping the .log suffix.
 * 
 * @code
 *     this->prm_log_dir = this->params.run_dir + "/log";
 *     cwd.mkpath(this->prm_log_dir);
 * 
 * 
 * 
 *     QDir::setCurrent(this->prm_log_dir);
 * 
 *     std::ofstream log_out_text( (prm_filename +".log" ).c_str() );
 *     prm_handler.print_parameters (log_out_text,
 *                                   dealii::ParameterHandler::Text);
 * 
 * @endcode
 * 
 * At this point the toplevel run dir must exist.
 * Thus, we can change to it without any further sanity test.
 * 
 * @code
 *     assert(QDir::setCurrent(this->params.run_dir ) );
 * 
 * @endcode
 * 
 * We know all the matrix sizes we are going to test and therefore
 * initialize @p results_table with the number of rows and columns of the test matrices.
 * 
 * @code
 *     for(unsigned int i = 0; i < this->params.matrix_sizes.size(); i++)
 *     {
 *         this->results_table.add_value("rows",  (int) this->params.matrix_sizes[i].first);
 *         this->results_table.add_value("columns", (int) this->params.matrix_sizes[i].second);
 *     }
 * }
 * 
 * @endcode
 * 
 * 
 * <a name="Functionrun"></a> 
 * <h4>Function: run</h4>
 * 
 * 
 * Running the performance test is done here.
 * 
 * @code
 * void step2::MyFancySimulation::run()
 * {
 * @endcode
 * 
 * The test runs are subdivided into groups for
 * single and double precision.
 * The list of matrix-vector product implementations
 * which are to be executed are stored as vector.
 * To keep the code short we introduce some references.
 * 
 * @code
 *     const std::vector<MVCase> & float_tests  = this->params.float_tests;
 *     const std::vector<MVCase> & double_tests = this->params.double_tests;
 * 
 * @endcode
 * 
 * For the comparisons of the runtimes we need the reverse, i.e. a mapping
 * from the name of the implementation to its index in the list of tests.
 * 
 * @code
 *     const std::map<MVCase, int> & float_vs  = this->params.float_vs;
 *     const std::map<MVCase, int> & double_vs = this->params.double_vs;
 * 
 * @endcode
 * 
 * In the benchmark tests we measure the runtimes for different matrix sizes.
 * The plot command for this raw data is assembled in
 * 
 * @code
 *     QString gpplots_runtimes;
 * 
 * @endcode
 * 
 * The interesting thing is which matrix-vector product is faster. To quantify this
 * we will compute the speedup of the CUDA implementations over ATLAS.
 * Basically, gnuplot can do this for us. The necessary plot commands are
 * stored in a separate string.
 * 
 * @code
 *     QString gpplots_speedup;
 * 
 * @endcode
 * 
 * The string @p gnuplot will contain all commands we want to pass to gnuplot
 * and merges the plot style settings with the plot commands.
 * For a full documentation of gnuplot's capabilities
 * have look at its <a href="http://www.gnuplot.info">online doc</a>.
 * 
 * @code
 *     QString gnuplot
 *             =
 * @endcode
 * 
 * We use the postscript terminal for publication-ready results.
 * 
 * @code
 *             "set term postscript landscape enhanced color solid "
 *             " linewidth 2.0 \"Helvetica\" 20\n"
 *             "set xlabel \"matrix entries\"\n"
 *             "set ylabel \"execution time\"\n"
 *             "set logscale xy\n"
 *             "set grid\n"
 *             "set output \"runtimes.ps\"\n"
 *             "set key inside left Left box lw 0.5\n";
 * 
 *     gnuplot += "plot ";
 * 
 * @endcode
 * 
 * Before we can complete the plot command we have to run the tests.
 * Float comes first.
 * 
 * @code
 *     std::vector<MVCase>::const_iterator
 *             t = float_tests.begin(),
 *             end_t = float_tests.end();
 * 
 *     int col = 3;
 * 
 *     for (; t != end_t; ++t)
 *     {
 *         MVTest<float> mv_test(this->params, results_table, *t);
 *         if(col > 3) gpplots_runtimes += ",";
 * @endcode
 * 
 * @p gpplots_runtimes contains all plot commands for the pure runtimes.
 * The relative path to the data file reflects the fact that we will call gnuplot
 * from a subdirectory of the run directory.
 * 
 * @code
 *         gpplots_runtimes += QString("\"../MVTest_results.out\" using (1*2):")
 * @endcode
 * 
 * Each run of @p mv_test appends an additional column with results to <i>MVTest_results.out</i>.
 * By stepping through the columns we can plot the respective runtime
 * 
 * @code
 *                 + QString::number(col++)
 *                 + QString(" title \"") + mv_test.run() + QString("\" w p");
 *     }
 * 
 * @endcode
 * 
 * Then come the double tests.
 * 
 * @code
 *     t = double_tests.begin(), end_t = double_tests.end();
 * 
 *     for (; t != end_t; ++t)
 *     {
 *         MVTest<double> mv_test(this->params, results_table, *t);
 *         if(col > 3) gpplots_runtimes += ",";
 * @endcode
 * 
 * After the tests have finished we can compose the plotting command for the double results
 * 
 * @code
 *         gpplots_runtimes += QString("\"../MVTest_results.out\" using (1*2):")
 *                 +
 *                 QString::number(col++)
 *                 +
 *                 QString(" title \"") + mv_test.run() + QString("\" w p");
 *     }
 * 
 * @endcode
 * 
 * Add the runtime plot commands to the global command string.
 * 
 * @code
 *     gnuplot += gpplots_runtimes;
 * 
 * @endcode
 * 
 * Then, set up titles for the speedup graphs.
 * 
 * @code
 *     gnuplot +=
 *             "\nset ylabel \"speedup\"\n"
 *             "set output \"speedup.ps\"\n"
 *             "set key inside left Left\n";
 * 
 * @endcode
 * 
 * For the speedups a linear scaling of the y-axis is more suitable
 * 
 * @code
 *     gnuplot += "unset logscale y\n";
 * 
 * @endcode
 * 
 * The order of the execution of the tests determines the order
 * in which the runtimes appear in @p results_table.
 * To compose the command string for plotting the speedups we use our lookup tables @p float_vs and @p double_vs
 * to find out which columns we have to use for
 * the calculation of the speedup.
 * The column index is associated with the kind of test (like @p atlas_mv). Using the test as key
 * the map returns the respective column to which we still have to add
 * a 3 since the map starts with index 0 but the first 2 columns
 * in our outputfile are reserved for the rows and columns of the matrix.
 * 
 * @code
 *     gnuplot += "plot";
 * 
 *     int offset = 3 + this->params.float_vs.size();
 * 
 *     if(this->params.run_cpublas_vs_cublas_float)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(float_vs.at(atlas_mv) + 3).arg(float_vs.at(cublas_mv) + 3)
 *                 + QString(" title \"CPU BLAS vs CUBLAS (float)\" w p");
 * 
 *     if(this->params.run_cpublas_vs_cublas_double)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(double_vs.at(atlas_mv) + offset).arg(double_vs.at(cublas_mv) + offset)
 *                 + QString(" title \"CPU BLAS vs CUBLAS (double)\" w p");
 * 
 *     if(this->params.run_cpublas_vs_Fujimoto_float)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(float_vs.at(atlas_mv) + 3).arg(float_vs.at(Fujimoto_mv) + 3)
 *                 + QString(" title \"CPU BLAS vs Fujimoto (float)\" w p");
 * 
 *     if(this->params.run_cpublas_vs_Fujimoto_double)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(double_vs.at(atlas_mv) + offset).arg(double_vs.at(Fujimoto_mv) + offset)
 *                 + QString(" title \"CPU BLAS vs Fujimoto (double)\" w p");
 * 
 *     if(this->params.run_Fujimoto_vs_cublas_float)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(float_vs.at(Fujimoto_mv) + 3).arg(float_vs.at(cublas_mv) + 3)
 *                 + QString(" title \"Fujimoto vs CUBLAS (float)\" w p");
 * 
 *     if(this->params.run_Fujimoto_vs_cublas_double)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(double_vs.at(Fujimoto_mv) + offset).arg(double_vs.at(cublas_mv) + offset)
 *                 + QString(" title \"Fujimoto vs CUBLAS (double)\" w p");
 * 
 * @endcode
 * 
 * When the plotting commands for the speedup are complete we can add them to the global command string.
 * 
 * @code
 *     gnuplot += gpplots_speedup;
 * 
 * @endcode
 * 
 * Besides plotting data gnuplot can also be employed as interface to the console. We use this to
 * convert the images from postscript to pdf and to remove old ps-files.
 * 
 * @code
 *     gnuplot += "\n!ps2pdf runtimes.ps runtimes.pdf";
 *     gnuplot += "\n!rm runtimes.ps";
 *     gnuplot += "\n!ps2pdf speedup.ps speedup.pdf";
 *     gnuplot += "\n!rm speedup.ps";
 * 
 * 
 *     std::cout << "Results are processed and saved.\n";
 * 
 * @endcode
 * 
 * Finally, save the runtimes to disc.
 * 
 * @code
 *     this->save_results();
 * 
 * @endcode
 * 
 * Then, we create the subdirectory for the plots from which gnuplot is going to be called.
 * 
 * @code
 *      QDir cwd = QDir::current();
 *      QString plot_dir = this->params.run_dir + "/plot";
 *              cwd.mkpath("./plot");
 * 
 *      QDir::setCurrent(plot_dir);
 * 
 * 
 * @endcode
 * 
 * We write the plotting commands from the string @p gnuplot to a file <i>plot.gp</i>,
 * 
 * @code
 *     QFile plotscript("plot.gp");
 * 
 *     bool success = plotscript.open(QIODevice::WriteOnly);
 *     if (!success)
 *         std::cerr << "Opening gnuplot file failed!" << std::endl;
 * 
 *     plotscript.write(gnuplot.toStdString().c_str());
 * 
 *     plotscript.close();
 * 
 *     if (! plotscript.exists() )
 *         std::cerr << "Writing gnuplot file failed!" << std::endl;
 * 
 * 
 * @endcode
 * 
 * open a pipe to gnuplot and load the plot file we have just created.
 * 
 * @code
 *     FILE *gp = popen("gnuplot -persist", "w");
 *     fprintf(gp, "load \"plot.gp\"\n");
 *     fflush(gp);
 * @endcode
 * 
 * After closing the pipe to gnuplot everything should have been plotted.
 * 
 * @code
 *     pclose(gp);
 * 
 * 
 *     QDir::setCurrent(this->params.run_dir);
 * 
 *     std::cout << "Finished." << std::endl;
 * }
 * 
 * @endcode
 * 
 * 
 * <a name="Functionsave_results"></a> 
 * <h4>Function: save_results</h4>
 * 
 * 
 * The final step in the benchmarking is to
 * save the content of @p results_table to a text file.
 * It should end up in the run directory given in the parameter file.
 * The header of the results file contains the information
 * about the sampling of the matrix sizes which allows to recreate
 * the input data at a later time solely from the results file.
 * 
 * @code
 * void step2::MyFancySimulation::save_results()
 * {
 *     std::string filename("MVTest_results");
 * 
 *     filename += ".out";
 * 
 *     std::ofstream out(filename.c_str());
 * 
 *     out << "# max n_cols  : " << this->params.max_n_cols << std::endl
 *         << "# min n_cols  : " << this->params.min_n_cols << std::endl
 *         << "# growth rate : " << this->params.n_rows_growth_rate << std::endl
 *         << std::endl;
 * 
 *     results_table.write_text(out);
 * }
 * 
 * #endif
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef SimUIParams_H
 * #define SimUIParams_H
 * 
 * @endcode
 * 
 * Before we discuss the implementation of the benchmarking we briefly go through the
 * parameters of the program which can be set at runtime.
 * 
 * 
 * The runtime parameters are grouped into several
 * simple structures. Their main purpose is to encapsulate the
 * declare() and get() functions needed to load the parameters by means
 * of the deal.II ParameterHandler class. These functions are all
 * very similar to each other
 * so that we do not present all of their definitions in this documentation.
 * To understand the program it suffices to know which parameters
 * have been declared. Hence, we merely include the definitions
 * of the parameter structures.
 * 

 * 
 * 
 * @code
 * #include <QString>
 * #include <deal.II/base/parameter_handler.h>
 * 
 * namespace step2 {
 * 
 * @endcode
 * 
 * 
 * <a name="EnumMVCase"></a> 
 * <h3>Enum: MVCase</h3>
 * 
 * 
 * These enumerated values will be used as tags for the different implementations of the matrix-vector product.
 * 
 * @code
 * enum MVCase { Fujimoto_mv, atlas_mv, cublas_mv, none / * for future use : , openmp_mv, ...* / };
 * 
 * @endcode
 * 
 * 
 * <a name="structSimUIParams"></a> 
 * <h3>struct: SimUIParams</h3>
 * 
 * 
 * This structure contains all parameters which are needed for each test.
 * These are essentially some flags which indicate whether the MV-test
 * has to be executed for a certain combination of numerical precision and
 * BLAS-implementation.
 * 
 * @code
 * struct SimUIParams {
 * 
 *     SimUIParams() {}
 * 
 *     static void declare(dealii::ParameterHandler & prm);
 * 
 *     void get(dealii::ParameterHandler & prm);
 * 
 * @endcode
 * 
 * The attributes consist of a long list of flags
 * indicating which combinations of tests are to be run ...
 * 
 * @code
 *     bool
 *     run_cpublas_vs_cublas_float,
 *     run_cpublas_vs_cublas_double,
 *     run_cpublas_vs_Fujimoto_float,
 *     run_cpublas_vs_Fujimoto_double,
 *     run_Fujimoto_vs_cublas_float,
 *     run_Fujimoto_vs_cublas_double;
 * 
 *     int fj_version;
 * 
 * @endcode
 * 
 * and a variable for holding the run directory.
 * 
 * @code
 *     QString run_dir;
 * 
 * @endcode
 * 
 * The test runs are subdivided into groups for
 * single and double precision.
 * The list of matrix-vector product implementations which are to be executed are stored as vector.
 * 
 * @code
 *     std::vector<MVCase> float_tests, double_tests;
 * @endcode
 * 
 * For the comparisons of the runtimes we need the reverse, i.e. a mapping
 * from the name of the implementation to its index in the list of tests.
 * 
 * @code
 *     std::map<MVCase, int> float_vs, double_vs;
 * 
 * private:
 *     SimUIParams (const SimUIParams & / *other* /) {}
 * 
 *     SimUIParams & operator = (const SimUIParams & / *other* /) { return *this; }
 * };
 * 
 * }
 * #endif // SimUIParams_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVTESTUIPARAMS_H
 * #define MVTESTUIPARAMS_H
 * 
 * #include <step-2/SimUIParams.h>
 * #include <step-2/DeviceParams.h>
 * #include <step-2/MVMultDriverInterface.h>
 * 
 * namespace step2 {
 * 
 * @endcode
 * 
 * 
 * <a name="ClassTestUIParamsBase"></a> 
 * <h3>Class: TestUIParamsBase</h3>
 * 
 * 
 * All factorization methods have to know the dimensions of the input
 * matrix and the destination where the results should be stored.
 * Therefore these details are collected in a separate class
 * which allows us to re-use them in other projects.
 * 
 * @code
 * struct TestUIParamsBase {
 * 
 *     TestUIParamsBase() {}
 * 
 *     static void declare(dealii::ParameterHandler & prm);
 * 
 *     void get(dealii::ParameterHandler & prm);
 * 
 * @endcode
 * 
 * problem size. A minimal and maximal column number is given.
 * 
 * @code
 *     int  min_n_cols;
 *     int  max_n_cols;
 * 
 * @endcode
 * 
 * growth-rate of rows until column number is reached.
 * 
 * @code
 *     double n_rows_growth_rate;
 * 
 * @endcode
 * 
 * For time measurements it is convenient to repeat the test several times and average over the results.
 * 
 * @code
 *     int n_repetitions;
 * 
 * 
 * private:
 * @endcode
 * 
 * Dummy implementation to avoid the automatic creation by the compiler.
 * Whenever an object should be copied this results in an error at compile-time.
 * 
 * @code
 *     TestUIParamsBase(const TestUIParamsBase & ) {}
 * 
 *     TestUIParamsBase & operator = (const TestUIParamsBase & / *other* /)
 *     {
 *         return *this;
 *     }
 * };
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="ClassMVTestUIParams"></a> 
 * <h3>Class: MVTestUIParams</h3>
 * 
 * 
 * All run-time parameters are assembled in this structure
 * so that they can be passed around as a whole.
 * We compose the different subsections by public inheritance.
 * 
 * @code
 * struct MVTestUIParams
 *         :
 *         public SimUIParams,
 *         public DeviceParams,
 *         public TestUIParamsBase
 * {
 *     MVTestUIParams()
 *         :
 *           SimUIParams(),
 *           DeviceParams(),
 *           TestUIParamsBase()
 *     {}
 * 
 *     static void declare(dealii::ParameterHandler & prm);
 * 
 *     void get(dealii::ParameterHandler & prm);
 * 
 * 
 *     int n_random_trials;
 * 
 *     std::vector<step2::matrixSize> matrix_sizes;
 * 
 * protected:
 *     void create_random_matrix_sizes();
 *     void create_regular_matrix_sizes();
 * 
 * private:
 *     MVTestUIParams (const MVTestUIParams & / *other* /)
 *         :
 *           SimUIParams(),
 *           DeviceParams(),
 *           TestUIParamsBase()
 *     {}
 * 
 *     MVTestUIParams & operator = (const MVTestUIParams & / *other* /)
 *     {
 *         return *this;
 *     }
 * };
 * 
 * }
 * #endif // MVTESTUIPARAMS_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVTEST_H
 * #define MVTEST_H
 * 
 * #include <QDir>
 * #include <step-2/Fujimoto_driver_step-2.h>
 * #include <step-2/cuda_driver_step-2.h>
 * #include <step-2/CpuBlas_driver_step-2.h>
 * #include <step-2/MVTestUIParams.h>
 * 
 * #include <deal.II/base/convergence_table.h>
 * 
 * namespace step2 {
 * 
 * @endcode
 * 
 * 
 * <a name="ClassMVTest"></a> 
 * <h3>Class: MVTest</h3>
 * 
 * 
 * This class drives the tests of the different tuning parameters
 * for Fujimoto's matrix-vector product or the test of the CUBLAS
 * or ATLAS (CPU) matrix-vector product.
 * The sole template parameter of this class is the number type,
 * i.e. real float and double
 * (or the complex counterparts in a future version).
 * 
 * @code
 * template <typename T>
 * class MVTest {
 * 
 * public:
 *     typedef ::FullMatrixAccessor<T> FullMatrixAccessor;
 * 
 *     MVTest(const MVTestUIParams & p,
 *            dealii::ConvergenceTable & results_table,
 *            MVCase variant=atlas_mv);
 * 
 *     ~MVTest();
 * 
 *     virtual QString run();
 * 
 * 
 * protected:
 *     typename step2::MVMultDriverInterface<T> * driver_m;
 * 
 *     virtual void setup_and_assemble(unsigned int nr,
 *                                     unsigned int nc);
 * 
 *     const MVTestUIParams * params;
 * 
 *     FullMatrixAccessor A;
 * 
 *     dealii::Vector<T> x_orig, y_orig;
 * 
 *     std::string col_head;
 * 
 *     dealii::ConvergenceTable & results_table;
 * };
 * }
 * #endif // MVTEST_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVTEST_HH
 * #define MVTEST_HH
 * 
 * #include <step-2/MVTest.h>
 * #include <step-2/PrecisionName.h>
 * #include <deal.II/base/convergence_table.h>
 * 
 * @endcode
 * 
 * 
 * <a name="Constructor"></a> 
 * <h4>Constructor</h4>
 * 
 * 
 * @param p : Reference to the full set of runtime parameters.
 * @param rt : Reference to the runtimes table.
 * @param mv_variant : Selects the implementation of the matrix-vector product.
 * 
 * @code
 * template <typename T>
 * step2::MVTest<T>::MVTest(const step2::MVTestUIParams & p,
 *                          dealii::ConvergenceTable &rt,
 *                          MVCase mv_variant)
 *     :
 *       params(&p),
 *       results_table(rt)
 * {
 *     driver_m = NULL;
 * 
 * @endcode
 * 
 * Depending on the variant we instantiate the driver
 * and choose a suitable header for the column in the results table.
 * 
 * @code
 *     switch (mv_variant) {
 * 
 *     case Fujimoto_mv:
 *         driver_m = new FujimotoDriver<T,cublas> (this->params->fj_version);
 *         col_head = "Fujimoto " + QString::number(this->params->fj_version).toStdString();
 *         break;
 *     case cublas_mv:
 *         driver_m = new CUBlasDriver<T,cublas> ();
 *         col_head  = "CUBLAS";
 *         break;
 *     case atlas_mv:
 *         driver_m = new step2::CpuBlasDriver<T,blas> ();
 *         col_head  = "CPU Blas";
 *         break;
 *     default: // do nothing
 *         break;
 *     }
 * 
 *     if (mv_variant != none)
 *     {
 *         assert(driver_m);
 * 
 * @endcode
 * 
 * After checking that we have successfully allocated the driver object
 * we append a string to the column header indicating the precision and number type
 * used in this test.
 * 
 * @code
 *         col_head += " " + PrecisionName<T>::name();
 * 
 * @endcode
 * 
 * Although it is not an error we use
 * 
 * @code
 *         std::cerr << "\nTesting " << col_head.c_str() << " mvmult "
 *                   << std::endl;
 * @endcode
 * 
 * so that QTCreator highlights this message in red.
 * 
 * @code
 *     }
 * }
 * 
 * @endcode
 * 
 * 
 * <a name="Destructor"></a> 
 * <h4>Destructor</h4>
 * 
 * 
 * 
 * @code
 * template <typename T>
 * step2::MVTest<T>::~MVTest()
 * {
 *     if (driver_m)
 *         delete driver_m;
 * }
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="Functionrun"></a> 
 * <h4>Function: run</h4>
 * 
 * 
 * This function manages the loop over the matrix sizes. The loops over the repetitions are delegated to the
 * different driver classes.
 * 
 * @code
 * template <typename T>
 * QString
 * step2::MVTest<T>::run()
 * {
 *     for (size_t i=0; i< this->params->matrix_sizes.size(); i++)
 *     {
 *         size_t nr = this->params->matrix_sizes[i].first ;
 *         size_t nc = this->params->matrix_sizes[i].second;
 * 
 * #ifdef DEBUG
 *         std::cout  << "Testing MV for " << nr << "x" << nc << " matrix" << std::endl;
 * #endif
 * @endcode
 * 
 * For unit testing purposes we reallocate the
 * complete matrix-vector multiplication test for each
 * matrix size to test.
 * 
 * @code
 *         setup_and_assemble(nr, nc);
 * 
 * 
 * @endcode
 * 
 * We copy the reference right-hand side into a local vector
 * and allocate a temporary destination vector.
 * 
 * @code
 *         std::vector<T> x(this->x_orig.begin(), this->x_orig.end());
 * 
 * @endcode
 * 
 * The reinitialization of @p y is done such that we can use it as matrix in
 * @ref step_3 "step-3" which tests different matrix-matrix multiplications.
 * 
 * @code
 *         unsigned int n_elements =  this->y_orig.size();
 *         std::vector<T> y(n_elements, 0.);
 * 
 *         double elapsed_time
 *                 =
 *                 driver_m->mvmult(y, A, x,
 *                                  this->params->n_repetitions) / this->params->n_repetitions;
 * 
 * @endcode
 * 
 * After the test we check whether @p y @p == @p y_orig.
 * As error measure we use the max-norm of the difference divided by the reference solution.
 * This yields an error roughly independent of the matrix size.
 * 

 * 
 * 
 * @code
 *         dealii::Vector<T> diff ( n_elements );
 *         for (unsigned int i = 0; i < n_elements; i++)
 *             diff(i) = (y[i] - y_orig(i)) / y_orig(i);
 * 
 *         double linfty_error = diff.linfty_norm();
 * 
 * @endcode
 * 
 * If the error appears to be too large, we print a warning message.
 * For sufficiently small vectors we dump them onto the screen.
 * 
 * @code
 *         if (linfty_error> (sizeof(T)<8 ? 1e-5 : 1e-14))
 *         {
 *             std::cerr << nr << "x" << nc << " matrix : "
 *                       << "|| (y - y_orig)/y_orig||_infty = " << linfty_error
 *                       << " MVTest probably failed!"
 *                       << std::endl;
 * 
 * @endcode
 * 
 * The maximum length of a vector which can still be reasonably displayed
 * in a terminal is something like 20. Since this is mostly needed when
 * debugging this magic number should not harm anything.
 * 
 * @code
 *             if (y.size() < 20) {
 *                 std::cerr << y_orig << std::endl;
 * 
 * @endcode
 * 
 * We do not need the @p diff vector anymore, so we use it
 * for storing the result of the matrix-vector product
 * such that it can be put into the out stream.
 * 
 * @code
 *                 std::copy(y.begin(), y.end(), diff.begin());
 *                 std::cerr << diff << std::endl;
 *             }
 *         }
 * 
 * @endcode
 * 
 * Finally, add the measured runtimes to the table collecting the results
 * and set the precision of the column's contents.
 * 
 * @code
 *         this->results_table.add_value(col_head.c_str(), elapsed_time);
 * 
 *         this->results_table.set_precision(col_head.c_str(), 12);
 *     }
 * 
 * @endcode
 * 
 * We return the header of the results column which simplifies the further processing of the results.
 * 
 * @code
 *     return col_head.c_str();
 * }
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="Functionsetup_and_assemble"></a> 
 * <h4>Function: setup_and_assemble</h4>
 * 
 * 
 * The second purpose of the MVTest class is the creation of reasonable test data.
 * This is done in this function. This is the place where one could use the deal.II examples
 * as blackbox matrix generators.
 * For the time being we define the entries of the
 * matrix $A \in \mathbb{R}^{m \times n}$,
 * the source vector $x\in \mathbb{R}^{n}$ and
 * destination $y\in \mathbb{R}^{m}$ as
 * \f{eqnarray}
 * A_{ik} & = & i + k\,, \\
 * x_k & = & \frac{1}{k}\,, \\
 * y_i& = & \sum_{k=1}^n A_{ik} x_k  = n + i\sum_{k=1}^n\frac{1}{k} \quad i \in
 * \lbrace 1, \ldots , m\rbrace\,.
 * \f}
 * Having different assembly routines is another possible extension of this program.
 * 
 * @code
 * template <typename T>
 * void
 * step2::MVTest<T>::setup_and_assemble(unsigned int nr, unsigned int nc)
 * {
 * @endcode
 * 
 * First we have to setup our linear system, i.e. to allocate enough memory.
 * 
 * @code
 *     this->A.reinit(nr, nc);
 *     this->x_orig.reinit(nc);
 *     this->y_orig.reinit(nr);
 * 
 * @endcode
 * 
 * Then we assemble. It would be nice to have that in parallel as well.
 * 
 * @code
 *     y_orig = 0.;
 *     int tmp = 1;
 *     for (unsigned int r = 0; r < nr; ++r)
 *         for (unsigned int c = 0; c < nc; ++c)
 *         {
 *             x_orig(c)  = (c+1);
 *             A(r,c)     = tmp; tmp++;//r+1 + 1./(c+1);
 *             y_orig(r) +=  A(r,c)*x_orig(c);
 *         }
 * }
 * #endif
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVMultDriverInterface_H
 * #define MVMultDriverInterface_H
 * 
 * #include <vector>
 * #include <numeric>
 * #include <lac/blas++.h>
 * 
 * @endcode
 * 
 * To avoid boring code we declare the member functions
 * of the classes defined in this file inline.
 * 
 * @code
 * namespace step2 {
 * 
 * typedef    std::pair<size_t, size_t> matrixSize;
 * 
 * @endcode
 * 
 * 
 * <a name="ClassMVMultDriverInterface"></a> 
 * <h3>Class: MVMultDriverInterface</h3>
 * 
 * 
 * This is the common base class for all matrix-vector
 * multiplications tested in this program. We define the
 * type of dense matrix which is to be used on the host side in this
 * class. As this is a template class w.r.t the data type of the matrix
 * entries the MVMultDriverInterface class has to be a template class as well.
 * 
 * @code
 * template<typename Number>
 * class MVMultDriverInterface {
 * 
 * public:
 * 
 *     typedef ::FullMatrixAccessor<Number> FullMatrixAccessor;
 * 
 *     MVMultDriverInterface()        {}
 * 
 *     virtual ~MVMultDriverInterface () {}
 * 
 * @endcode
 * 
 * 
 * <a name="Functionmvmult"></a> 
 * <h4>Function: mvmult</h4>
 * 
 * 
 * This function has to implement the profiling of a
 * matrix-vector product in a derived class. There is
 * no reasonable default implementation thus we make this an
 * abstract virtual function.
 * @param y : The vector for the result of $Ax$.
 * @param A : The matrix to multiply with @p $x$.
 * @param x : The source vector.
 * @param n_repetitions : How many times the matrix-vector product is to be run.
 * @return : cumulative runtime.
 * 
 * @code
 *     virtual double mvmult(std::vector<Number> & y,
 *                           const FullMatrixAccessor & A,
 *                           const std::vector<Number> & x,
 *                           int n_repetitions) = 0;
 * };
 * 
 * } // namespace step2 END
 * #endif // MVMultDriverInterface_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CPUBLAS_DRIVER_STEP2_H
 * #define CPUBLAS_DRIVER_STEP2_H
 * 
 * #include <vector>
 * #include <lac/blas++.h>
 * #include <step-2/MVMultDriverInterface.h>
 * 
 * namespace step2 {
 * 
 * @endcode
 * 
 * 
 * <a name="ClassCpuBlasDriver"></a> 
 * <h3>Class: CpuBlasDriver</h3>
 * 
 * 
 * The first of our driver classes implements the CPU-based
 * matrix-vector multiplication.
 * 
 * @code
 * template<typename EntryType, typename blasType>
 * class CpuBlasDriver : public MVMultDriverInterface<EntryType>
 * {
 * public:
 * 
 *     typedef
 *     typename MVMultDriverInterface< EntryType>::FullMatrixAccessor
 *     FullMatrixAccessor;
 * 
 *     CpuBlasDriver() {}
 * 
 *     virtual ~CpuBlasDriver () {}
 * 
 * @endcode
 * 
 * The only function of interest of this class is the
 * one which profiles the matrix-vector multiplication.
 * 
 * @code
 *     virtual double mvmult(std::vector<EntryType>& y,
 *                           const FullMatrixAccessor& A,
 *                           const std::vector<EntryType>& x,
 *                           int n_repetitions);
 * };
 * 
 * } // namespace step2 END
 * 
 * @endcode
 * 
 * In standard C++ it is a good habit to separate function declarations
 * from their definitions. For template classes this does not work.
 * Therefore, we put the definitions of the member functions into a
 * separate header file to keep at least the improved overview provided
 * by this separation.
 * 
 * @code
 * #include <step-2/CpuBlas_driver_step-2.hh>
 * #endif // CPUBLAS_DRIVER_STEP2_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CPUBLAS_DRIVER_STEP_2_HH
 * #define CPUBLAS_DRIVER_STEP_2_HH
 * 
 * #include <base/CUDATimer.h>
 * 
 * @endcode
 * 
 * 
 * <a name="Functionmvmult"></a> 
 * <h4>Function: mvmult</h4>
 * 
 * 
 * We overload the mvmult() function from the base class
 * to delegate the execution of the matrix-vector product
 * to the ATLAS library.
 * 
 * @code
 * template<typename EntryType,typename blasType>
 * double step2::CpuBlasDriver<EntryType,blasType>::mvmult(std::vector<EntryType>& y,
 *                                                         const FullMatrixAccessor& A,
 *                                                         const std::vector<EntryType>& x,
 *                                                         int n_repetitions)
 * {
 * @endcode
 * 
 * We introduce some convenience variables.
 * 
 * @code
 *     int n_rows = A.n_rows();
 *     int n_cols = A.n_cols();
 * 
 * @endcode
 * 
 * For better readability we
 * create local variables for
 * the arguments of the BLAS function.
 * 
 * @code
 *     EntryType * d_y = &y[0];
 * 
 *     EntryType * d_A = const_cast<FullMatrixAccessor &>(A).val();
 * 
 *     EntryType * d_x = &const_cast<std::vector<EntryType> &>(x)[0];
 * 
 *     EntryType alpha = 1;
 *     EntryType beta  = 1;
 * 
 *     int incx = 1; int incy = 1;
 * 
 * @endcode
 * 
 * Internally, BLAS assumes a column-major
 * storage of the matrix. Therefore, the leading
 * dimension is the number of columns.
 * 
 * @code
 *     int lda = n_cols;
 * 
 * @endcode
 * 
 * However, we use a row-major ordering and thus have to invoke
 * BLAS' gemv() function such that it performs the transposed matrix-vector product.
 * To do this, we have to swap the roles of the number of rows and columns
 * and pass a 't' as first argument to gemv().
 * 
 * @code
 *     int m = n_cols;
 *     int n = n_rows;
 * 
 * @endcode
 * 
 * We execute the matrix-vector product several times
 * for a given matrix size to get a reliable estimate of the runtime.
 * 
 * @code
 *     double cumulative_runtime = 0.;
 *     for (int i=0; i<n_repetitions; i++)
 *     {
 * @endcode
 * 
 * BLAS does not take care of properly initializing
 * the result vector to zero. Hence, we have to do it ourselves.
 * 
 * @code
 *         for (unsigned int k = 0; k < n_rows; k++)
 *             d_y[k] = 0.;
 * 
 *         CUDATimer timer;
 * 
 *         blasType::gemv ('t', m, n, alpha,
 *                         d_A, lda,
 *                         d_x, incx,
 *                         beta,
 *                         d_y, incy);
 * 
 *         timer.stop();
 *         cumulative_runtime += timer.elapsed();
 *     }
 * 
 *     return cumulative_runtime;
 * }
 * #endif // CPUBLAS_DRIVER_STEP_2_HH
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CUBlasDriver_STEP_2_H
 * #define CUBlasDriver_STEP_2_H
 * 
 * #include <vector>
 * #include <lac/blas++.h>
 * #include <step-2/MVMultDriverInterface.h>
 * 
 * namespace step2 {
 * 
 * @endcode
 * 
 * 
 * <a name="ClassCUBlasDriver"></a> 
 * <h3>Class: CUBlasDriver</h3>
 * 
 * 
 * In contrast to the CpuBlasDriver class which has just wrapped
 * the blas function into the mvmult() function for providing
 * a more comfortable progammer's interface
 * this class additionally has to manage the host-device-communication,
 * i.e. the data transfer between the two different memories.
 * 
 * @code
 * template<typename T,typename blasType=cublas>
 * class CUBlasDriver : public MVMultDriverInterface<T>
 * {
 * public:
 *     typedef
 *     typename MVMultDriverInterface<T>::FullMatrixAccessor
 *     FullMatrixAccessor;
 * 
 * 
 *     CUBlasDriver();
 * 
 *     virtual ~CUBlasDriver ();
 * 
 *     virtual double mvmult(std::vector<T>& y,
 *                           const FullMatrixAccessor& A,
 *                           const std::vector<T>& x,
 *                           int        n_repetitions);
 * };
 * 
 * } // namespace step2 END
 * 
 * #include <step-2/cuda_driver_step-2.hh>
 * #endif // CUBlasDriver_STEP_2_H
 * 
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CUDA_DRIVER_STEP_2_HH
 * #define CUDA_DRIVER_STEP_2_HH
 * 
 * #include <base/CUDATimer.h>
 * 
 * @endcode
 * 
 * 
 * <a name="ConstructorCUBlasDriver"></a> 
 * <h4>Constructor: CUBlasDriver</h4>
 * 
 * 
 * In case of CUBLAS the constructor and destructor
 * take care of initializing the library and shutting it down again.
 * 
 * @code
 * template<typename T,typename blasType>
 * step2::CUBlasDriver<T,blasType>::CUBlasDriver() : MVMultDriverInterface<T>()
 * {
 *     blasType::Init();
 * }
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="DestructorCUBlasDriver"></a> 
 * <h4>Destructor: CUBlasDriver</h4>
 * 
 * @code
 * template<typename T,typename blasType>
 * step2::CUBlasDriver<T,blasType>::~CUBlasDriver()
 * {
 *     blasType::Shutdown();
 * }
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="Functionmvmult"></a> 
 * <h4>Function: mvmult</h4>
 * 
 * 
 * For details about the function arguments see the base class.
 * 
 * @code
 * template<typename T,typename blasType>
 * double step2::CUBlasDriver<T,blasType>::mvmult(std::vector<T>& y,
 *                                                const FullMatrixAccessor& A,
 *                                                const std::vector<T>& x,
 *                                                int n_repetitions)
 * {   
 * @endcode
 * 
 * As before, we introduce some convenience variables
 * and local variables for the arguments of the BLAS function.
 * 
 * @code
 *     int n_rows = A.n_rows();
 *     int n_cols = A.n_cols();
 * 
 *     T * dst = &y[0];
 * 
 *     T * A_entries = const_cast<FullMatrixAccessor &>(A).val();
 * 
 *     T * src = &const_cast<std::vector<T> &>(x)[0];
 * 
 *     T alpha=1.;
 *     T beta=1.;
 *     int incx=1;
 *     int incy=1;
 * 
 * @endcode
 * 
 * Since CUBLAS is also designed to work column-major everything we have said in the body of
 * CpuBlasDriver::mvmult() applies here as well.
 * 
 * @code
 *     int lda=n_cols;
 *     int m = n_cols;
 *     int n = n_rows;
 * 
 * @endcode
 * 
 * Up to this point there is no difference to CpuBlasDriver::mvmult().
 * In order to use CUBLAS we have to copy the matrix, the source and the destination vector
 * to the device.
 * To do this, we have to declare pointers in the device memory ...
 * 
 * @code
 *     T *d_A, *d_x, *d_y;
 * 
 * @endcode
 * 
 * allocate enough space ...
 * 
 * @code
 *     cudaMalloc((void **) &d_A, n_rows * n_cols * sizeof(T));
 * 
 *     cudaMalloc((void **) &d_x, n_cols * sizeof(T));
 *     cudaMalloc((void **) &d_y, n_rows * sizeof(T));
 * 
 * @endcode
 * 
 * and copy everything from host to device.
 * 
 * @code
 *     cudaMemcpy(d_x, src, n_cols * sizeof(T), cudaMemcpyHostToDevice);
 * 
 *     cudaMemcpy(d_A, A_entries, n_rows * n_cols * sizeof(T), cudaMemcpyHostToDevice);
 * 
 * @endcode
 * 
 * <p> It should be obvious that excessive use of @p cudaMalloc, @p cudaMemcpy and @p cudaFree quickly
 * becomes error-prone and leads to a lot of redundant code.
 * To remedy this, we have introduced our SciPal library which hides memory transfers behind assignment
 * operators and the bare blas functions
 * are wrapped up in an operator-based interface for linear algebra operations.</p>
 * 
 * 
 * After these preparations we execute the CUBLAS version of gemv() via SciPal's CUBLAS wrapper
 * which allows us to use a precision-independent formulation. After each run we have to synchronize
 * in order to measure the actual runtime and not the time CUBLAS needs to start its kernels.
 * 
 * @code
 *     double cumulative_runtime = 0.;
 *     for (int i=0; i<n_repetitions; i++)
 *     {
 *         cudaThreadSynchronize();
 *         CUDATimer timer;
 * 
 * @endcode
 * 
 * Like BLAS, CUBLAS does not take care of properly initializing
 * the result vector to zero. Hence, for each run we copy the
 * vector from the host to the device.
 * 
 * @code
 *         cudaMemcpy(d_y, dst, n_rows * sizeof(T), cudaMemcpyHostToDevice);
 * 
 *         blasType::gemv ('t', m, n, alpha,
 *                         d_A, lda,
 *                         d_x,  incx,
 *                         beta,
 *                         d_y,  incy);
 * 
 *         cudaThreadSynchronize();
 *         timer.stop();
 *         cumulative_runtime += timer.elapsed();
 *     }
 * 
 * @endcode
 * 
 * Once we are done, we can copy the result back to the host
 * and return the cumulative runtime.
 * 
 * @code
 *     cudaMemcpy(dst, d_y, n_rows * sizeof(T), cudaMemcpyDeviceToHost);
 * 
 * @endcode
 * 
 * After the test is complete, we deallocate the arrays on the device.
 * 
 * @code
 *     cudaFree(d_y);
 *     cudaFree(d_x);
 *     cudaFree(d_A);
 * 
 *     return cumulative_runtime;
 * }
 * #endif // CUDA_DRIVER_STEP_2_HH
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef FUJIMOTO_DRIVER_step2_H
 * #define FUJIMOTO_DRIVER_step2_H
 * 
 * #include <vector>
 * #include <lac/blas++.h>
 * #include <step-2/MVMultDriverInterface.h>
 * #include <step-2/cuda_kernel_wrapper_step-2.cu.h>
 * 
 * namespace step2 {
 * 
 * @endcode
 * 
 * 
 * <a name="ClassFujimotoDriver"></a> 
 * <h3>Class: FujimotoDriver</h3>
 * 
 * 
 * The most interesting variant is the matrix-vector product by Fujimoto.
 * Although it is executed on the GPU its driver class is more similar to
 * CpuBlasDriver because the management of the host-device memory transfers
 * is moved into the wrapper function of the CUDA kernel.
 * We use private inheritance for the Kernels<T> structure to express the "is implemented with" relationship.
 * 
 * @code
 * template<typename T,typename blasType=cublas>
 * class FujimotoDriver : public MVMultDriverInterface<T>, private Kernels<T>
 * {
 * public:
 *     typedef
 *     typename MVMultDriverInterface<T>::FullMatrixAccessor FullMatrixAccessor;
 * 
 *     FujimotoDriver(const int v) : fj_version(v) {}
 * 
 *     virtual  ~FujimotoDriver () {}
 * 
 *     virtual double mvmult(std::vector<T>& y,
 *                           const FullMatrixAccessor& A,
 *                           const std::vector<T>& x,
 *                           int n_repetitions);
 * 
 * protected:
 *     const int fj_version;
 * };
 * 
 * } // namespace step2 END
 * 
 * #include <step-2/Fujimoto_driver_step-2.hh>
 * #endif // FUJIMOTO_DRIVER_step2_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef FUJIMOTO_DRIVER_step2_HH
 * #define FUJIMOTO_DRIVER_step2_HH
 * 
 * #include <step-2/cuda_kernel_wrapper_step-2.cu.h>
 * #include <base/CUDATimer.h>
 * 
 * @endcode
 * 
 * 
 * <a name="Functionmvmult"></a> 
 * <h4>Function: mvmult</h4>
 * 
 * 
 * For details about the function arguments see the base class.
 * It is very similar to CpuBlasDriver::mvmult(). The major differences are
 * that instead of a blas function a CUDA kernel is invoked and that the measurement of the runtime
 * is moved into the kernel wrapper function which gives us a cumulative runtime and not an average.
 * 
 * @code
 * template<typename Number,typename blasType>
 * double step2::FujimotoDriver<Number,blasType>::mvmult(std::vector<Number> & y,
 *                                                       const FullMatrixAccessor& A,
 *                                                       const std::vector<Number> & x,
 *                                                       int n_repetitions)
 * {
 *     int n_rows = A.n_rows();
 *     int n_cols = A.n_cols();
 * 
 *     Number * dst = &y[0];
 * 
 *     const Number * A_entries = A.val();
 * 
 *     const Number * src = &x[0];
 * 
 * 
 *     double cumulative_elapsed_time = 0;
 * 
 *     this->mv_fujimoto(dst, A_entries, src,
 *                       n_rows, n_cols,
 *                       n_repetitions,
 *                       this->fj_version,
 *                       cumulative_elapsed_time);
 * 
 *     return cumulative_elapsed_time;
 * }
 * 
 * #endif // FUJIMOTO_DRIVER_step2_HH
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CUDA_KERNEL_STEP_2_CU_H
 * #define CUDA_KERNEL_STEP_2_CU_H
 * 
 * @endcode
 * 
 * 
 * <a name="DeclarationofCUDAInterface"></a> 
 * <h3>Declaration of CUDA Interface</h3>
 * 
 * 
 * 
 * @code
 * namespace step2 {
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="ClassKernels"></a> 
 * <h3>Class: Kernels</h3>
 * 
 * 
 * In our example programs we try to encapsulate CUDA as much as possible such that
 * CUDA-independent parts of the source code can be reused easily.
 * Especially, we want to localize CUDA-specific extensions of the C/C++language in only a few files.
 * The bridge between these two parts is formed by the Kernels class.
 * Its member functions mirror the arguments of the CUDA kernels and their bodies
 * provide the encapsulation of the non-standard syntax for the kernels calls.
 * Currently, there is only one wrapper function for the kernel by Fujimoto.
 * Often kernels can be implemented in a type-independent way. Therefore, the Kernels
 * class is templated with respect to the number type.
 * 
 * @code
 * template<typename T>
 * struct Kernels {
 * 
 *     void mv_fujimoto(T *y, const T *A, const T *x,
 *                      const int m, const int n,
 *                      const int n_repetitions, const int fj_version, double& elapsed_time);
 * };
 * }
 * #endif // CUDA_KERNEL_STEP_2_CU_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * 
 * #include <step-2/cuda_kernel_wrapper_step-2.cu.h>
 * 
 * @endcode
 * 
 * On OSX10.9 the CUDATimer class causes linker errors. Therefore, we disable it.
 * #define DONT_USE_CUDATIMER
 * 

 * 
 * 
 * @code
 * #ifndef DONT_USE_CUDATIMER
 * #include <base/CUDATimer.h>
 * #endif
 * 
 * @endcode
 * 
 * With the advent of the Fermi architecture
 * it became possible to use the printf command from within a kernel.
 * To enable this feature one has to include the corresponding header from the C standard library.
 * 
 * @code
 * #include <stdio.h>
 * 
 * @endcode
 * 
 * 
 * <a name="Kernels"></a> 
 * <h3>Kernels</h3>
 * 
 * 
 * The core of any CUDA-based application are its kernels. They are the place where the
 * actual numerical labour is executed.
 * Like on the host side we put all kernels in a separate namespace
 * to avoid collisions with other steps.
 * 
 * 
 * 
 * @code
 * namespace step2 {
 * 
 * @endcode
 * 
 * To shorten the kernel code we introduce some abbreviations for built-in variables.
 * 
 * @code
 * #define bx blockIdx.x
 * #define tx threadIdx.x
 * #define ty threadIdx.y
 * 
 * 
 * @endcode
 * 
 * The crucial idea of Fujimoto's method is to use
 * the texture cache(s) to speed up the reading of the matrix by tiling and accessing it as a texture,
 * as we have already mentioned in the introduction.
 * To manage textures CUDA allows to either define texture objects or texture references
 * (for the details have a look at the programming guide, Sec. 3.2.10).
 * We follow Fujimoto and use references.
 * A subtlety of texture references is that they must exist as global variables in the same file as the kernel
 * which is going to access them.
 * In computer graphics it is often desirable to normalize the values read from a texture to the
 * range [-1., +1] or [0, +1.] depending on whether they are signed or unsigned.
 * Defining the access as <i>cudaReadModeElementType</i> assures that
 * during the texture fetch the data is read "as is".
 * The immutable parameters needed at compile time are the element type, the spatial dimension and the type of access.
 * 
 * @code
 * texture<float4, 2, cudaReadModeElementType> fTexRefA;
 * 
 * @endcode
 * 
 * 
 * <a name="Kernel_mv_fujimoto"></a> 
 * <h4>Kernel: _mv_fujimoto</h4>
 * 
 * 
 * This is the CUDA kernel for the matrix-vector multiplication
 * 
 * 
 * \f{equation}
 * y = Ax
 * \f}
 * introduced by Noriyuki Fujimoto.
 * 
 * 
 * Copyright (C) 2008 Noriyuki Fujimoto, All Rights Reserved
 * Fujimoto@mi.s.osakafu-u.ac.jp
 * 
 * 
 * Please refer the paper below if you use Fujimoto's algorithm in your published work :
 * 
 * 
 * Noriyuki Fujimoto, Faster Matrix-Vector Multiplication on GeForce 8800GTX,
 * In the Proceedings of the 22nd IEEE International Parallel and
 * Distributed Processing Symposium (IPDPS), LSPP-402, pp.1-8, April 2008
 * 
 * 
 * This CUDA kernel heavily relies on bitshift operations.
 * A good review can be found <a href="http://www.cprogramming.com/tutorial/bitwise_operators.html">here</a>.
 * 
 * 
 * We start with the original version to explain the details of the parallelization.
 * Afterwards we generalize it to double precision, consider the dependence of performance on the bitshifting and discuss
 * an improved way of reading a double-precision matrix.
 * 
 * 
 * To parallelize the multiplication of a large, dense matrix with a dense vector the matrix gets subdivided
 * into small tiles.
 * One row of tiles is assigned to one thread block of 16 x 16 threads. These sizes are chosen such that no thread of a
 * block is idle when the entries of the vector are loaded into shared memory.
 * Each thread block loads one tile at a time and computes
 * its product with the corresponding slice from the source vectors.
 * @param y : pointer to array containing the entries of the results vector.
 * @param A : pointer to a cudaArray which the matrix has been copied.
 * @param x : pointer to array containing the entries of the source vector.
 * @param m : Number of rows of the matrix. The internal dimensions of the cudaArray may be different.
 * @param n : Number of columns of the matrix. The internal dimensions of the cudaArray may be different.
 * 
 * @code
 * __global__
 * void
 * _mv_fujimoto(float* y, cudaArray* A, float* x, int m, int n)
 * {
 * @endcode
 * 
 * In the original version each 16x16 threadblock computes the matrix-vector product
 * of a 16x16 submatrix of the texture
 * with 256 entries of the source vector $x$ at a time.
 * Due to the frequent reuse of the vector entries they are stored in shared memory.
 * 
 * @code
 *     __shared__ float xs[16][16];
 * 
 * @endcode
 * 
 * The intermediate partial sums are buffered in shared memory
 * 
 * @code
 *     __shared__ float Ps[16][16];
 * 
 * @endcode
 * 
 * and the matrix entries read from the texture in a small vector.
 * 
 * @code
 *     float4 a;
 * 
 * @endcode
 * 
 * The 2D matrix indices must be converted to a 1D index
 * (leftshift of 4 = multiplication with 16 (2^4) which is the blocksize)
 * 
 * @code
 *     float *Psptr = (float *) Ps + (ty << 4) + tx;
 * @endcode
 * 
 * Then we determine the $y$ coordinate of the position in the texture, i.e. the global row index
 * 
 * @code
 *     int ay = (bx << 4) + ty;
 * @endcode
 * 
 * The entries of the solution vector
 * and the partial sums which will be computed by this thread
 * are addressed via pointers to hide the index arithmetic.
 * 
 * @code
 *     float *xptr = x + (ty << 4) + tx;
 *     float *xsptr = (float *) xs + (tx << 2);
 * 
 * @endcode
 * 
 * Each thread initializes its partial sum to 0.
 * 
 * @code
 *     *Psptr = 0.0f;
 * 
 * @endcode
 * 
 * Since the loop over the column index gets partially unrolled we have to define
 * it outside the loop unlike standard C++ procedure.
 * 
 * @code
 *     int i;
 * @endcode
 * 
 * Each row of a thread block deals with one row of the matrix.
 * Each thread walks through the texture with a stride of 64 and computes
 * the scalar product of 4 consecutive matrix elements
 * with 4 consecutive elements of the source vector.
 * The loop for the scalar product is unrolled.
 * With respect to the individual matrix elements this leads to an outer stride of 256.
 * Hence, one row of threads in the thread block simultaneously works on 64 texture elements
 * or 256 matrix and source vector elements respectively.
 * Thus, there are no idle threads for most of the time especially when the next bunch of source vector entries is loaded.
 * Exceptions may occur when the threads have reached the right boundary of the matrix.
 * 
 * @code
 *     for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *     {
 * @endcode
 * 
 * Since the source vector entries are the only ones which can be reused
 * they are copied into shared memory.
 * 
 * @code
 *         xs[ty][tx] = *xptr;
 *         __syncthreads();
 * 
 * @endcode
 * 
 * The core of the algorithm is to compute the scalar product
 * of 4 consecutive entries of a matrix row
 * with the corresponding subvector of the source vector.
 * The matrix is read through a texture to take advantage of their optimization with respect
 * to 2D spatial locality. Each texture element
 * represents 4 consecutive entries of a matrix row as float4, i.e. a vector of 4 floats.
 * 
 * 
 * The texture elements are formed by 4-component vectors.
 * The 16 threads of one row of the thread block are supposed to read 16 consecutive texture elements.
 * Therefore, the $x$ coordinate for the texture fetch is given by the $x$ component of the
 * thread index @p tx plus the column index @p i divided by 4.
 * The division is realized by shifting the bits of @p i to the right.
 * This algorithm is also illustrated in
 * <a href="http://ch.nvidia.com/docs/IO/47905/fujimoto_lspp2008.pdf">Fujimoto's paper</a>.
 * 
 * @code
 *         int ax = tx + (i >> 2);
 * 
 *         a = tex2D(fTexRefA, ax     , ay);
 * @endcode
 * 
 * After reading the texture element we can compute the inner product of @p a with the corresponding
 * 4 entries of @p x. This is done by all threads and thus simultaneously for 64 consecutive elements
 * of $x$.
 * 
 * @code
 *         *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 * @endcode
 * 
 * The next statements repeat this procedure for the remaining 3 subgroups comprising
 * 64 elements of $x$ each.
 * 
 * @code
 *         a = tex2D(fTexRefA, ax + 16, ay);
 *         *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *         a = tex2D(fTexRefA, ax + 32, ay);
 *         *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *         a = tex2D(fTexRefA, ax + 48, ay);
 *         *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *         __syncthreads();
 *     }
 * 
 * @endcode
 * 
 * At this point the number of remaining columns does not suffice to keep all threads busy with the unrolling strategy.
 * Especially, there are less than 256 vector entries which still can be read.
 * 
 * @code
 *     if (i + (ty << 4) + tx < n) {
 *         xs[ty][tx] = *xptr;
 *     }
 *     __syncthreads();
 * 
 * @endcode
 * 
 * After reading what is left over the 16 threads of a row in the thread block
 * work on the remaining columns in chunks of 64. Increasing @p xsptr only by 61
 * in each iteration is due to the fact that it is already incremented in the body of the
 * loop three times.
 * 
 * @code
 *     int j;
 *     for (j = 0; j < ((n - i) >> 6); j++, xsptr += 61) {
 *         a = tex2D(fTexRefA, tx + (i >> 2) + (j << 4), ay);
 *         *Psptr += a.x * *xsptr++ + a.y * *xsptr++ + a.z * *xsptr++ + a.w * *xsptr;
 *     }
 *     __syncthreads();
 * 
 * @endcode
 * 
 * When there are less than 64 columns left some threads have to stay idle while the rest
 * finishes the job.
 * 
 * @code
 *     int remain = (n - i) & 63;
 * 
 *     if ((tx << 2) < remain) {
 *         a = tex2D(fTexRefA, tx + (i >> 2) + (j << 4), ay);
 *         *Psptr += a.x * *xsptr++;
 *     }
 *     if ((tx << 2) + 1 < remain) *Psptr += a.y * *xsptr++;
 *     if ((tx << 2) + 2 < remain) *Psptr += a.z * *xsptr++;
 *     if ((tx << 2) + 3 < remain) *Psptr += a.w * *xsptr;
 *     __syncthreads();
 * 
 * @endcode
 * 
 * The last step, before we can write the result to global memory,
 * is to reduce the partial sums into one.
 * 
 * @code
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 *     __syncthreads();
 * 
 *     if (ty == 0 && (bx << 4) + tx < m) y[(bx << 4) + tx] = Ps[tx][0];
 * }
 * 
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="Kernel_mv_fujimoto_T"></a> 
 * <h4>Kernel: _mv_fujimoto_T</h4>
 * 
 * 
 * A limitation of Fujimoto's original kernel is that it is implemented
 * only for single-precision, real-valued matrices.
 * Here, we show how to extend it to double precision. Complex numbers should be similar.
 * 
 * 
 * The first thing we need is a structure which allows us to distinguish floats from doubles at compile-time.
 * 
 * @code
 * template<typename T>
 * struct IsFloat;
 * 
 * template<>
 * struct IsFloat<float>
 * {
 *     static const bool value = true;
 * };
 * 
 * template<typename T>
 * struct IsFloat
 * {
 *     static const bool value = false;
 * };
 * 
 * @endcode
 * 
 * Then we need a template structure which depending on the number type @p T of the matrix elements provides
 * the correct data types for the texture elements and the buffer of the matrix elements.
 * Further, it has to provide the stride for the texture access which is needed in the determination
 * of the effective width of the cudaArray through which the texture is accessed, see below in the wrapper function.
 * 
 * @code
 * template<typename T>
 * struct TexEl;
 * 
 * @endcode
 * 
 * For single-precision, real numbers we need the types and values from the original implementation.
 * 
 * @code
 * template<>
 * struct TexEl<float>
 * {
 *     typedef float4 value_type;
 *     typedef float4 alt_value_type;
 *     typedef float4 texel_type;
 *     static const int tex_stride = 4;
 * };
 * 
 * @endcode
 * 
 * For double precision we can use @p double4 as buffer but there are no such texture fetches. Therefore,
 * we have to compose the texture of elements of type @p int4 and each double has to be reconstructed from 2 ints
 * using CUDA's @p __hiloint2double function.
 * 
 * 
 * For later use we introduce @p double2 as alternative value type.
 * 
 * @code
 * template<>
 * struct TexEl<double>
 * {
 *     typedef double4 value_type;
 *     typedef double2 alt_value_type;
 *     typedef int4 texel_type;
 *     static const int tex_stride = 2;
 * };
 * 
 * @endcode
 * 
 * Last but not least we need a separate texture reference for double precision.
 * 
 * @code
 * texture<TexEl<double>::texel_type, 2, cudaReadModeElementType> dTexRefA;
 * 
 * 
 * @endcode
 * 
 * The problem with the texture references is that we have to define one for each data type.
 * Yet, we want to abstract the fetching from the data type. To do this, we define a little structure
 * for the texture access which only provides an overloaded operator().
 * 
 * @code
 * template<typename T>
 * struct texAccessor {
 * 
 *     __device__
 *     typename TexEl<T>::value_type
 *     operator() (int ax, int ay);
 * 
 * };
 * 
 * @endcode
 * 
 * Depending on the template specialization we can access the different texture references.
 * For single precision we return what we fetch right away.
 * 
 * @code
 * template<>
 * TexEl<float>::value_type texAccessor<float>::operator() (int ax, int ay)
 * {
 *     return tex2D(fTexRefA, ax, ay);
 * }
 * 
 * @endcode
 * 
 * In case of double precision this is also place where we reconstruct the matrix entries.
 * 
 * @code
 * template<>
 * TexEl<double>::value_type texAccessor<double>::operator() (int ax, int ay)
 * {
 *     TexEl<double>::texel_type tmp;
 *     TexEl<double>::value_type a;
 * 
 *     tmp = tex2D(dTexRefA, 2*ax, ay);
 *     a.x = __hiloint2double(tmp.y, tmp.x);
 *     a.y = __hiloint2double(tmp.w, tmp.z);
 * 
 *     tmp = tex2D(dTexRefA, 2*ax+1, ay);
 *     a.z = __hiloint2double(tmp.y, tmp.x);
 *     a.w = __hiloint2double(tmp.w, tmp.z);
 * 
 * #ifndef nDEBUG
 *     printf("a : %f, %f, %f, %f\n", a.x, a.y, a.z, a.w);
 * #endif
 *     return a;
 * }
 * 
 * @endcode
 * 
 * Since there are only so few changes we only comment the differences.
 * First of all, all occurences of @p float are replaced by @p T.
 * 
 * @code
 * template<typename T>
 * __global__
 * void
 * _mv_fujimoto_T( T* y, cudaArray* A, T* x, int m, int n)
 * {
 *     __shared__ T xs[16][16];
 * 
 *     __shared__ T Ps[16][16];
 * 
 * @endcode
 * 
 * Instead of a hard-coded type for buffer for the matrix elements
 * we let the TexEl structure determine the correct type from
 * which particular @T is passed in as template argument.
 * This is typical template metaprogramming.
 * 
 * @code
 *     typename TexEl<T>::value_type a;
 * 
 *     T *Psptr = (T *) Ps + (ty << 4) + tx;
 * 
 *     int ay = (bx << 4) + ty;
 * 
 *     T *xptr = x + (ty << 4) + tx;
 *     T *xsptr = (T *) xs + (tx << 2);
 * 
 *     *Psptr = 0.0f;
 *     int i;
 * 
 * @endcode
 * 
 * In contrast to the original kernel we now need
 * an accessor object for the texture fetches which
 * eliminiates the texture reference from the list of arguments of the texture fetch.
 * 
 * @code
 *     texAccessor<T> tex_2D;
 * 
 * @endcode
 * 
 * Except for the changes in the texture fetches everything else remains unchanged.
 * 
 * @code
 *     for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *     {
 *         xs[ty][tx] = *xptr;
 *         __syncthreads();
 * 
 *         int ax = tx + (i >> 2);
 * 
 *         a = tex_2D(ax, ay);
 *         *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 *         a = tex_2D(ax+16, ay);
 *         *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *         a = tex_2D(ax+32, ay);
 *         *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *         a = tex_2D(ax+48, ay);
 *         *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *         __syncthreads();
 *     }
 * 
 *     if (i + (ty << 4) + tx < n) {
 *         xs[ty][tx] = *xptr;
 *     }
 *     __syncthreads();
 * 
 *     int j;
 *     for (j = 0; j < ((n - i) >> 6); j++, xsptr += 61) {
 *         a = tex_2D(tx + (i >> 2) + (j << 4), ay);
 *         *Psptr += a.x * *xsptr++ + a.y * *xsptr++    +     a.z * *xsptr++ + a.w * *xsptr;
 *     }
 *     __syncthreads();
 * 
 *     int remain = (n - i) & 63;
 *     if ((tx << 2) < remain) {
 *         a = tex_2D(tx + (i >> 2) + (j << 4), ay);
 * 
 *         *Psptr += a.x * *xsptr++;
 *     }
 *     if ((tx << 2) + 1 < remain) *Psptr += a.y * *xsptr++;
 *     if ((tx << 2) + 2 < remain) *Psptr += a.z * *xsptr++;
 *     if ((tx << 2) + 3 < remain) *Psptr += a.w * *xsptr;
 *     __syncthreads();
 * 
 * 
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 * 
 *     __syncthreads();
 *     if (ty == 0 && (bx << 4) + tx < m) y[(bx << 4) + tx] = Ps[tx][0];
 * }
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="Kernel_mv_fujimoto_T2"></a> 
 * <h4>Kernel: _mv_fujimoto_T2</h4>
 * 
 * 
 * Bitshifting maybe efficient. Yet it limits the readability of the code.
 * Therefore, we provide one version where the bitshift operations are replaced by
 * multiplications and divisions. Running the different Fujimoto versions then gives an overview
 * of whether that technique pays off. Except for the bitshifts everything else is a verbatim copy
 * of the previous kernel.
 * 
 * @code
 * template<typename T>
 * __global__
 * void
 * _mv_fujimoto_T2( T* y, cudaArray* A, T* x, int m, int n)
 * {
 *     __shared__ T xs[16][16];
 * 
 *     __shared__ T Ps[16][16];
 * 
 *     typename TexEl<T>::value_type a;
 * 
 *     T *Psptr = (T *) Ps + (16*ty) + tx;
 * 
 *     int ay = (16*bx) + ty;
 * 
 *     T *xptr = x + (16*ty) + tx;
 *     T *xsptr = (T *) xs + (4*tx);
 * 
 *     *Psptr = 0.0f;
 *     int i;
 * 
 *     texAccessor<T> tex_2D;
 * 
 * 
 *     for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *     {
 *         xs[ty][tx] = *xptr;
 *         __syncthreads();
 * 
 *         int ax = tx + (i/4);
 * 
 *         a = tex_2D(ax, ay);
 *         *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 *         a = tex_2D(ax+16, ay);
 *         *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *         a = tex_2D(ax+32, ay);
 *         *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *         a = tex_2D(ax+48, ay);
 *         *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *         __syncthreads();
 *     }
 * 
 *     if (i + (16*ty) + tx < n) {
 *         xs[ty][tx] = *xptr;
 *     }
 *     __syncthreads();
 * 
 *     int j;
 *     for (j = 0; j < ((n - i)/64); j++, xsptr += 61) {
 *         a = tex_2D(tx + (i/4) + (16*j), ay);
 *         *Psptr += a.x * *xsptr++ + a.y * *xsptr++    +     a.z * *xsptr++ + a.w * *xsptr;
 *     }
 *     __syncthreads();
 * 
 *     int remain = (n - i) & 63;
 *     if ((4*tx) < remain) {
 *         a = tex_2D(tx + (i/4) + (16*j), ay);
 * 
 *         *Psptr += a.x * *xsptr++;
 *     }
 *     if ((4*tx) + 1 < remain) *Psptr += a.y * *xsptr++;
 *     if ((4*tx) + 2 < remain) *Psptr += a.z * *xsptr++;
 *     if ((4*tx) + 3 < remain) *Psptr += a.w * *xsptr;
 *     __syncthreads();
 * 
 * 
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 * 
 *     __syncthreads();
 *     if (ty == 0 && (16*bx) + tx < m) y[(16*bx) + tx] = Ps[tx][0];
 * }
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="Kernel_mv_fujimoto_T3"></a> 
 * <h4>Kernel: _mv_fujimoto_T3</h4>
 * 
 * 
 * The next issue is the optimization of double precision performance. The way it is handled up to now should
 * lead to warps running at only half of their possible memory bandwidth.
 * To change that we have to modify the texAccessor class and the magic numbers in the unrolled innermost loop.
 * 
 * @code
 * template<typename T>
 * struct texAccessorOpt {
 * 
 *     __device__
 *     typename TexEl<T>::alt_value_type
 *     operator() (int ax, int ay);
 * 
 * };
 * 
 * @endcode
 * 
 * Depending on the template specialization we can access the different texture references.
 * For single precision nothing changes.
 * 
 * @code
 * template<>
 * TexEl<float>::alt_value_type texAccessorOpt<float>::operator() (int ax, int ay)
 * {
 *     return tex2D(fTexRefA, ax, ay);
 * }
 * 
 * @endcode
 * 
 * In case of double precision we now read only one texture element.
 * This has to be compensated in the magic numbers for the partial unrolling of the loop over the columns of a row.
 * 
 * @code
 * template<>
 * TexEl<double>::alt_value_type texAccessorOpt<double>::operator() (int ax, int ay)
 * {
 *     TexEl<double>::texel_type tmp;
 *     TexEl<double>::alt_value_type a;
 * 
 *     tmp = tex2D(dTexRefA, ax, ay);
 *     a.x = __hiloint2double(tmp.y, tmp.x);
 *     a.y = __hiloint2double(tmp.w, tmp.z);
 * 
 * #ifdef DEBUG
 *     printf("a : %f, %f\n", a.x, a.y);
 * #endif
 *     return a;
 * }
 * 
 * @endcode
 * 
 * In the kernel we distinguish between floats and doubles using our IsFloat structure.
 * 
 * @code
 * template<typename T>
 * __global__
 * void
 * _mv_fujimoto_T3( T* y, cudaArray* A, T* x, int m, int n)
 * {
 *     __shared__ T xs[16][16];
 * 
 *     __shared__ T Ps[16][16];
 * 
 * 
 *     T *Psptr = (T *) Ps + (16*ty) + tx;
 * 
 *     int ay = (16*bx) + ty;
 * 
 *     T *xptr = x + (16*ty) + tx;
 * 
 * 
 *     *Psptr = 0.0f;
 *     int i;
 * 
 *     if(IsFloat<T>::value==true)
 *     {
 *         T *xsptr = (T *) xs + (4*tx);
 *         typename TexEl<T>::value_type a;
 *         texAccessor<T> tex_2D;
 *         for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *         {
 *             xs[ty][tx] = *xptr;
 *             __syncthreads();
 * 
 *             int ax = tx + (i/4);
 * 
 *             a = tex_2D(ax, ay);
 *              printf("a : %f, %f, %f, %f\n", a.x, a.y, a.z, a.w);
 *             *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 *             a = tex_2D(ax+16, ay);
 *             *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *             a = tex_2D(ax+32, ay);
 *             *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *             a = tex_2D(ax+48, ay);
 *             *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *             __syncthreads();
 *         }
 * 
 *         if (i + (16*ty) + tx < n) {
 *             xs[ty][tx] = *xptr;
 *         }
 *         __syncthreads();
 * 
 * 
 *         int j;
 *         for (j = 0; j < ((n - i)/64); j++, xsptr += 61) {
 *             a = tex_2D(tx + (i/4) + (16*j), ay);
 *             *Psptr += a.x * *xsptr++ + a.y * *xsptr++ + a.z * *xsptr++ + a.w * *xsptr;
 *         }
 *         __syncthreads();
 * 
 * 
 *         int remain = (n - i) & 63;
 *         if ((4*tx) < remain) {
 *             a = tex_2D(tx + (i/4) + (16*j), ay);
 * 
 *             *Psptr += a.x * *xsptr++;
 *         }
 *         if ((4*tx) + 1 < remain) *Psptr += a.y * *xsptr++;
 *         if ((4*tx) + 2 < remain) *Psptr += a.z * *xsptr++;
 *         if ((4*tx) + 3 < remain) *Psptr += a.w * *xsptr;
 *         __syncthreads();
 *     }
 * @endcode
 * 
 * For double precision we still have 16 multiplications in the innermost unrolled loop but we have to read
 * twice as often from the texture. Yet, it is done such that threads read contiguous pieces of memory when
 * the instruction for a texture fetch is issued unlike before.
 * 
 * @code
 *     else {
 *         T *xsptr = (T *) xs + (2*tx);
 * 
 *         typename TexEl<T>::alt_value_type a;
 * 
 *         texAccessorOpt<T> tex_2D;
 * 
 *         for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *         {
 *             xs[ty][tx] = *xptr;
 * 
 *             __syncthreads();
 * 
 *             int ax = tx + (i/2);
 * 
 * 
 *             a = tex_2D(ax, ay);
 *             *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1);
 * 
 *             a = tex_2D(ax+16, ay);
 *             *Psptr += a.x * *(xsptr +  32) + a.y * *(xsptr +  33);
 * 
 *             a = tex_2D(ax+32, ay);
 *             *Psptr += a.x * *(xsptr + 64) + a.y * *(xsptr + 65);
 * 
 *             a = tex_2D(ax+48, ay);
 *             *Psptr += a.x * *(xsptr + 96) + a.y * *(xsptr + 97);
 * 
 *             a = tex_2D(ax+64, ay);
 *             *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129);
 * 
 *             a = tex_2D(ax+80, ay);
 *             *Psptr += a.x * *(xsptr + 160) + a.y * *(xsptr + 161);
 * 
 *             a = tex_2D(ax+96, ay);
 *             *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193);
 * 
 *             a = tex_2D(ax+112, ay);
 *             *Psptr += a.x * *(xsptr + 224) + a.y * *(xsptr + 225);
 * 
 *             __syncthreads();
 *         }
 * 
 *         if (i + (16*ty) + tx < n) xs[ty][tx] = *xptr;
 * 
 *         __syncthreads();
 * 
 * 
 *         int j;
 * 
 *         for (j = 0; j < ((n - i)/32); j++, xsptr += 31)
 *         {
 *             a = tex_2D(tx + (i/2) + (16*j), ay);
 *             *Psptr += a.x * *xsptr++ + a.y * *xsptr;
 *         }
 *         __syncthreads();
 * 
 * 
 *         int remain = (n - i) & 31;
 * 
 *         if ((2*tx) < remain) {
 *             a = tex_2D(tx + (i/2) + (16*j), ay);
 * 
 *             *Psptr += a.x * *xsptr++;
 *         }
 * 
 *         if ( (2*tx) + 1 < remain)
 *         {
 *             *Psptr += a.y * *xsptr;
 *         }
 * 
 *         __syncthreads();
 *     }
 * 
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 * 
 *     __syncthreads();
 *     if (ty == 0 && (16*bx) + tx < m) y[(16*bx) + tx] = Ps[tx][0];
 * }
 * 
 * 
 * @endcode
 * 
 * 
 * <a name="Functionmv_fujimoto"></a> 
 * <h4>Function: mv_fujimoto</h4>
 * 
 * 
 * After all the kernels we finally have to define the wrapper function for the
 * kernel call.
 * Its task is to setup the size of the thread blocks and the size of the grid
 * which depends on the dimensions of the matrix.
 * Furthermore, it binds the texture, allocates the memory and copies the
 * matrix and vectors to the device.
 * after all this is done it starts the selected kernel and when it has finished copies the result
 * back to the host.
 * To accomodate for the original kernel we have to provide an auxiliary wrapper function
 * which in the case float calls Fujimoto's kernel and in all other cases does nothing.
 * 
 * @code
 * void __do_FJ_orig(float* d_y, cudaArray* d_A, float* d_x, int m, int n, dim3 grid, dim3 threads)
 * {
 *     _mv_fujimoto<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 * }
 * 
 * void __do_FJ_orig(double* , cudaArray* , double* , int , int , dim3 , dim3 )
 * {
 *     printf("For double precision the original version of Fujimoto is not available!\n");
 * }
 * 
 * @endcode
 * 
 * After these preparations we can define the generic wrapper function.
 * 
 * @code
 * template<typename T>
 * void Kernels<T>::mv_fujimoto(T *y, const T *A, const T *x, const int m, const int n,
 *                              const int n_repetitions,
 *                              const int fj_version,
 *                              double&  elapsed_time)
 * {
 * 
 * @endcode
 * 
 * To compute the number of blocks we have to divide the number of rows @p m
 * by 16 and add 1, if (m mod 16) != 0.
 * We keep the original version by Fujimoto as comment.
 * 
 * @code
 *     int blkNum = (m + 15)/16; // (m >> 4) + ((m & 15) ? 1 : 0);
 *     int height = blkNum*16; // blkNum << 4;
 * 
 * @endcode
 * 
 * For the width we have to do the same but with 16 replaced by 256.
 * 
 * @code
 *     int width = 256*((n+255)/256); // (n & 255) ? (((n >> 8) + 1) << 8) : n;
 * 
 * @endcode
 * 
 * Each row of a thread block deals with one row of the matrix.
 * 
 * @code
 *     dim3 threads(16, 16);
 * @endcode
 * 
 * Therefore, we need a one-dimensional grid of thread blocks which is large enough
 * so that all rows of the matrix are covered.
 * 
 * @code
 *     dim3 grid(blkNum, 1);
 * 
 * @endcode
 * 
 * The crucial idea of Fujimoto is to read the matrix via the texture cache.
 * To do this, the matrix must be stored in a cudaArray.
 * 
 * @code
 *     cudaArray *d_A;
 *     T *d_x, *d_y;
 * 
 * @endcode
 * 
 * In contrast to Fujimoto we do not
 * pass the type of the texture element directly to the channel description
 * but ask the TexEl structure for it. The original version is kept in a comment.
 * 
 * @code
 *     cudaChannelFormatDesc
 *             channelDesc = cudaCreateChannelDesc<typename TexEl<T>::texel_type/ *float4* />();
 * 
 * @endcode
 * 
 * In case of float we can store the matrix entries as float4.
 * Therefore, the width of the cudaArray is only
 * @p width/4.
 * For double precision we store 2 doubles as one int4 which requires
 * twice as much texels per row. Thus, the width of the cudaArray is
 * @p width/2.
 * To select these numbers automatically we use the static constant
 * @p tex_stride from the TeXEl structure.
 * 
 * @code
 *     cudaMallocArray(&d_A, &channelDesc, width/TexEl<T>::tex_stride, height);
 * 
 *     size_t size_of_T = sizeof(T);
 * 
 *     cudaMemcpy2DToArray(d_A, 0, 0, A,
 *                         n * size_of_T,
 *                         n * size_of_T,
 *                         m,
 *                         cudaMemcpyHostToDevice);
 * 
 * 
 * @endcode
 * 
 * The reference to the texture is created at runtime.
 * Depending on the number type we either bind the float4 or int4 texture.
 * 
 * @code
 *     if (IsFloat<T>::value)
 *         cudaBindTextureToArray(fTexRefA, d_A);
 *     else
 *         cudaBindTextureToArray(dTexRefA, d_A);
 * 
 *     cudaMalloc((void **) &d_x, n * size_of_T );
 *     cudaMalloc((void **) &d_y, m * size_of_T );
 * 
 *     cudaMemcpy(d_x, x, n * size_of_T, cudaMemcpyHostToDevice);
 * 
 * @endcode
 * 
 * Although the final values of matrix-vector product are assigned to  @p d_y
 * the result is only correct if we initialize
 * @p d_y with zeros. To do this, we copy for each run the
 * vector from the host to the device.
 * 
 * @code
 * #ifndef DONT_USE_CUDATIMER
 *     CUDATimer timer;
 * #endif
 *     for (int i=0; i<n_repetitions; i++)
 *     {
 *         cudaMemcpy(d_y, y, m * size_of_T, cudaMemcpyHostToDevice);
 *         switch (fj_version) {
 *         case 0:
 *             __do_FJ_orig(d_y, d_A, d_x, m, n, grid, threads);
 *             break;
 *         case 1:
 *             _mv_fujimoto_T<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 *             break;
 *         case 2:
 *             _mv_fujimoto_T2<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 *             break;
 *         case 3:
 *             _mv_fujimoto_T3<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 *             break;
 *         default:
 *             break;
 *         }
 *     }
 *     cudaThreadSynchronize();
 * #ifndef DONT_USE_CUDATIMER
 *     timer.stop();
 *     elapsed_time = timer.elapsed() ;
 * #else
 *     elapsed_time = 3.1415926;
 * #endif
 * #ifdef DEBUG
 * #ifndef DONT_USE_CUDATIMER
 *     timer.print_elapsed("Time spent in Fujimotos MV product:");
 * #endif
 * #endif
 * 
 * @endcode
 * 
 * After the matrix-vector products are done we copy the result back to the host and clean up.
 * 
 * @code
 *     cudaMemcpy(y, d_y, m * size_of_T, cudaMemcpyDeviceToHost);
 * 
 *     cudaFree(d_y);
 *     cudaFree(d_x);
 * 
 * @endcode
 * 
 * Depending on which texture we have bound we have to selectively unbind.
 * 
 * @code
 *     if(IsFloat<T>::value)
 *         cudaUnbindTexture( fTexRefA);
 *     else
 *         cudaUnbindTexture( dTexRefA);
 *     cudaFreeArray(d_A);
 * }
 * 
 * @endcode
 * 
 * This 2-liner provides all possible template specializations
 * for real-valued matrices and finally explains why we enclosed the wrapper functions in a structure.
 * 
 * @code
 * template class Kernels<float>;
 * template class Kernels<double>;
 * 
 * } // namespace step2 END
 * 
 * 
 * 
 * 
 * 
 * @endcode
<a name="Results"></a><h1>Results</h1>

<p>
Before we show the results, we want to describe briefly how to use the program.
</p>
<p>
The easiest way is to load the step-2.pro into QtCreator and hit the play button.
 The program is then executed with its default parameters.
</p>
<p>
The execution path and arguments which are passed to the executable
can be changed in the project settings in QTCreator
(in this case the only valid argument is the location of the parameter file).
It may also be necessary to change the LD_LIBRARY_PATH such that all necessary libraries are found.
<p>
\htmlimage{qt_config.png, 700, Screen shot of the project settings window in QtCreator.
You should uncheck "Run in Terminal"\, because it frequently causes problems.}
</p>
</p>
<p>
The results of the different tests are provided in the following plots. The first
depicts runtime measurements obtained on a Tesla K20c GPU and a Dell T7500 workstation
with two X5675 Xeons each with 6 cores.
From this raw data we compute the speedups of the GPU-based methods over the CPU
reference implementation provided by ATLAS.
Then, we compare the different Fujimoto variants with each other and last but not least show
the memory bandwidth achieved by CUBLAS and the different Fujimoto versions.
</p>

<p>
\htmlimage{runtimes_150ppi.png, 700,
Runtimes for Fujimoto\, ATLAS and CUBLAS matrix-vector products. In contrast to ATLAS
the CUDA-based methods
display a considerable startup overhead as for small matrix sizes the runtime is almost constant.}
</p>

<p>
\htmlimage{speedup-logplot_150ppi.png, 700, Speedup of Fujimoto and CUBLAS over ATLAS.
For sufficiently large matrices the GPU is saturated and the speedup becomes constant as expected.}
</p>


<p>
\htmlimage{speedup-FJ-bitshift_150ppi.png, 700,
Comparison of Fujimotos original kernel with bitshifts
against the float version of the generic implementation without bitshifts.
Values larger 1 favor the bitshift version by
Fujimoto whereas values less than 1 indicate that bitshifting does not pay off.
Due to the large scattering
there is no clear winner. }
</p>


<p>
\htmlimage{speedup-FJ-double-opt_150ppi.png, 700, Unlike bitshifting the optimization of the
texture fetches for double precision does pay off which is indicated by values larger than 1.}
</p>

<!--
<p>
\htmlimage{speedup-FJ-vs-CUBLAS_150ppi.png, 700, As in 2008 it }
</p>
-->

<p>
\htmlimage{speedup-logplot-FJ-vs-CUBLAS_150ppi.png, 700,
As in 2008 Fujimoto's kernel is faster than
the gemv function from CUBLAS which now is indicated by values less than 1.
For large matrices Fujimoto needs approximately only half the time as CUBLAS.
Our extension to double precision
shares this feature although not that prominent but there is still a gain of 20-30% over CUBLAS.}
</p>
<!--


  speedup-logplot_150ppi.png

-->


<p>
\htmlimage{bandwidths_150ppi.png, 700, Estimated memory bandwidth
for different Fujimoto variants and CUBLAS for single and double precision.
To compute the bandwidth we divide the memory consumed by the matrix by the runtime.
For small matrices this is a bit conservative because the vectors are not yet negligible.
These numbers are also more conservative as the results one obtains with NVVP. }
</p>


<a name="Plots"></a><h3>Plots</h3>

<p>
After the performance tests have been completed, the results are stored in
the file <i>MVTest_results.out</i>.
During execution a gnuplot script in the <code>plot</code> subdirectory is generated
and produces the corresponding plots.
<br />



<br />
The parameters used to generate the plots above are listed in the following lines:
</p>
<pre>
# Listing of Parameters
# ---------------------

subsection Dimensions of test problems.
  # Binary logarithm of minimal number of columns of upper triangular matrix
  # R. Allowed range : [3,15]
  set log2(max n cols)   = 13.001

  # Binary logarithm of minimal number of columns of upper triangular matrix
  # R. Allowed range : [2,15]
  set log2(min n cols)   = 3

  # Perform the test for this many randomly chosen matrix sizes.If the value
  # given is 0, then a list of matrix sizes is used which is generated
  # deterministically from the growth strategy.
  set n random trials    = 0

  # Repeat the test for a given matrix size this many times.
  set n repetitions      = 20

  # In each test instance the number of rows of R is increased by this factor.
  # Allowed range : [1.1,10]
  set n rows growth rate = 1.12517
end


subsection Global parameters
  # CPU-BLAS and CUBLAS double.
  set Run CPU-BLAS vs CUBLAS double   = false

  # CPU-BLAS and CUBLAS float.
  set Run CPU-BLAS vs CUBLAS float    = false

  # CPU-BLAS and Fujimoto double.
  set Run CPU-BLAS vs Fujimoto double = false

  # CPU-BLAS and Fujimoto float.
  set Run CPU-BLAS vs Fujimoto float  = false

  # Fujimoto and CUBLAS double.
  set Run Fujimoto vs CUBLAS double   = true

  # Fujimoto and CUBLAS float.
  set Run Fujimoto vs CUBLAS float    = false

end


subsection Fujimoto parameters

  # In case of float the <generic> version is a verbatim copy
  # of the original version. In case of double the reading of the matrix
  # induces 50% idle threads. <no bitshift> is identical to the generic version
  # except that index arithmetic is done in a more human readable fashion.
  # <double optimization> provides optimized access to the matrix entries
  # in the case of double precision.
  # possible values : generic|no bitshift|double optimization
  set Fujimoto variant = generic #original #|double optimization

end

subsection Simulation basics
  # Specify a directory results of the test are to be stored. This can be
  # either an absolute path or path relative to the directory where the
  # program has been started. The default is subdir called test_me-<date>
  # where <date> will be replaced by the date at which the program has been
  # started. this simplifies keeping the projects directory clean
  set Run directory = ../step-2/reference-results/Thu-25-04-2013-FJ-generic-vs-CUBLAS-double-max_8192x8192

end

subsection Device flags
  # This allows to dedicate the local L1 caches completely to buffering
  # register spilling effects.
  set Disable L1 caching for global memory = false

  # This allows to rather use 48 KB as L1 cache.
  set Maximize L1 cache                    = false

  # This allows to access the matrix via texture and not by direct memory
  # accesses. On older hardware textures can exploit the 2D locality of matrix
  # entries. On Fermi- or Kepler-based GPUs this should not make much sense.
  set Wrap matrix into texture             = true
end
</pre>

 * <a name="PlainProg"></a>
 * <h1> The plain program</h1>
 * 
 * (If you are looking at a locally installed CUDA HPC Praktikum version, then the
 * program can be found at <i>
 *  .. /.. /testsite / /step-2 /step-cu.cc
 * </i>. Otherwise, this is only
 * the path on some remote server.)
 @code

 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #include <step-2/step-2.hh>
 * 
@endcode
 <a name="plain-Functionmain"></a>
@code
 * int main(int argc, char *argv[])
 * {
 *     step2::MyFancySimulation sim(argc, argv);
 * 
 *     sim.run();
 * }
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef STEP_2_HH
 * #define STEP_2_HH
 * #include <cstdio>
 * #include <vector>
 * 
 * #include <deal.II/base/convergence_table.h>
 * 
 * #include <cuda_runtime.h>
 * #include <../SciPAL/include/base/GPUInfo.h>
 * 
 * #include <QString>
 * 
 * #include <step-2/MVTest.h>
 * #include <step-2/MVTest.hh>
 * 
 * #include <step-2/MVTestUIParams.h>
 * 
 * namespace step2 {
 * 
@endcode
 <a name="plain-ClassMyFancySimulation"></a>
@code
 * class MyFancySimulation {
 * 
 * public:
 *    MyFancySimulation(int argc, char *argv[]);
 * 
 *    virtual void run();
 * 
 * protected:
 *     virtual void save_results();
 * 
 * 
 *     dealii::ConvergenceTable results_table;
 * 
 *     MVTestUIParams params;
 * 
 *     SciPAL::GPUInfo gpu_info;
 * 
 *     QString launch_dir;
 * 
 *     QString prm_dir;
 * 
 *     QString prm_log_dir;
 * };
 * 
 * }
 * 
@endcode
 <a name="plain-ConstructorMyFancySimulation"></a>
@code
 * step2::MyFancySimulation::MyFancySimulation(int argc, char *argv[])
 * {
 *     cudaGetDeviceCount(&gpu_info.n_CUDA_devices);
 *     std::cout
 *             << "N available CUDA devices : "
 *             << gpu_info.n_CUDA_devices << std::endl;
 * 
 *     gpu_info.get();
 * 
 *     dealii::ParameterHandler prm_handler;
 * 
 *     MVTestUIParams::declare(prm_handler);
 * 
 *      QDir cwd = QDir::current();
 *      cwd.makeAbsolute();
 * 
 *    this->launch_dir = cwd.absolutePath();
 * 
 *     std::string prm_filename;
 * 
 *     if (argc == 1)
 *     {
 *         QFileInfo tmp(argv[0]);
 *         this->prm_dir = tmp.absolutePath() + "/prm";
 *         prm_filename  = tmp.fileName().toStdString();
 *         prm_filename += ".prm";
 *     }
 *     else
 *     {
 *         std::cout << "Given parameter file : " << argv[1] << std::endl;
 * 
 *         QFileInfo tmp(argv[1]);
 * 
 *         if(!tmp.exists())
 *         {
 *             std::cerr << "The following parameter file does not exist:\n"
 *                       << argv[1] << std::endl;
 * 
 *             qFatal("Cannot proceed without proper path to parameter file");
 *         }
 * 
 *         this->prm_dir = tmp.absolutePath();
 * 
 *         prm_filename = tmp.fileName().toStdString();
 * 
 *         std::cout << "xx Parameter file path : "
 *                   << tmp.absolutePath().toStdString().c_str()
 *                   << std::endl;
 *     }
 * 
 *     std::cout << "Parameter file : " << prm_filename  << std::endl;
 * 
 *     cwd.mkpath(this->prm_dir);
 * 
 *     std::cout << "step-2: prm path : " << this->prm_dir.toStdString().c_str()  << std::endl;
 * 
 *     QDir::setCurrent(this->prm_dir);
 * 
 *     prm_handler.read_input (prm_filename);
 * 
 *     this->params.get(prm_handler);
 * 
 *     QDir::setCurrent(this->launch_dir);
 *     cwd.mkpath(this->params.run_dir);
 *     QDir::setCurrent(this->params.run_dir);
 *     cwd = QDir::current();
 *     this->params.run_dir = cwd.absolutePath();
 * 
 *     std::cout << "Entering run dir : " << this->params.run_dir.toStdString().c_str()  << std::endl;
 * 
 * 
 * 
 *     this->prm_log_dir = this->params.run_dir + "/log";
 *     cwd.mkpath(this->prm_log_dir);
 * 
 * 
 * 
 *     QDir::setCurrent(this->prm_log_dir);
 * 
 *     std::ofstream log_out_text( (prm_filename +".log" ).c_str() );
 *     prm_handler.print_parameters (log_out_text,
 *                                   dealii::ParameterHandler::Text);
 * 
 *     assert(QDir::setCurrent(this->params.run_dir ) );
 * 
 *     for(unsigned int i = 0; i < this->params.matrix_sizes.size(); i++)
 *     {
 *         this->results_table.add_value("rows",  (int) this->params.matrix_sizes[i].first);
 *         this->results_table.add_value("columns", (int) this->params.matrix_sizes[i].second);
 *     }
 * }
 * 
@endcode
 <a name="plain-Functionrun"></a>
@code
 * void step2::MyFancySimulation::run()
 * {
 *     const std::vector<MVCase> & float_tests  = this->params.float_tests;
 *     const std::vector<MVCase> & double_tests = this->params.double_tests;
 * 
 *     const std::map<MVCase, int> & float_vs  = this->params.float_vs;
 *     const std::map<MVCase, int> & double_vs = this->params.double_vs;
 * 
 *     QString gpplots_runtimes;
 * 
 *     QString gpplots_speedup;
 * 
 *     QString gnuplot
 *             =
 *             "set term postscript landscape enhanced color solid "
 *             " linewidth 2.0 \"Helvetica\" 20\n"
 *             "set xlabel \"matrix entries\"\n"
 *             "set ylabel \"execution time\"\n"
 *             "set logscale xy\n"
 *             "set grid\n"
 *             "set output \"runtimes.ps\"\n"
 *             "set key inside left Left box lw 0.5\n";
 * 
 *     gnuplot += "plot ";
 * 
 *     std::vector<MVCase>::const_iterator
 *             t = float_tests.begin(),
 *             end_t = float_tests.end();
 * 
 *     int col = 3;
 * 
 *     for (; t != end_t; ++t)
 *     {
 *         MVTest<float> mv_test(this->params, results_table, *t);
 *         if(col > 3) gpplots_runtimes += ",";
 *         gpplots_runtimes += QString("\"../MVTest_results.out\" using (1*2):")
 *                 + QString::number(col++)
 *                 + QString(" title \"") + mv_test.run() + QString("\" w p");
 *     }
 * 
 *     t = double_tests.begin(), end_t = double_tests.end();
 * 
 *     for (; t != end_t; ++t)
 *     {
 *         MVTest<double> mv_test(this->params, results_table, *t);
 *         if(col > 3) gpplots_runtimes += ",";
 *         gpplots_runtimes += QString("\"../MVTest_results.out\" using (1*2):")
 *                 +
 *                 QString::number(col++)
 *                 +
 *                 QString(" title \"") + mv_test.run() + QString("\" w p");
 *     }
 * 
 *     gnuplot += gpplots_runtimes;
 * 
 *     gnuplot +=
 *             "\nset ylabel \"speedup\"\n"
 *             "set output \"speedup.ps\"\n"
 *             "set key inside left Left\n";
 * 
 *     gnuplot += "unset logscale y\n";
 * 
 *     gnuplot += "plot";
 * 
 *     int offset = 3 + this->params.float_vs.size();
 * 
 *     if(this->params.run_cpublas_vs_cublas_float)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(float_vs.at(atlas_mv) + 3).arg(float_vs.at(cublas_mv) + 3)
 *                 + QString(" title \"CPU BLAS vs CUBLAS (float)\" w p");
 * 
 *     if(this->params.run_cpublas_vs_cublas_double)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(double_vs.at(atlas_mv) + offset).arg(double_vs.at(cublas_mv) + offset)
 *                 + QString(" title \"CPU BLAS vs CUBLAS (double)\" w p");
 * 
 *     if(this->params.run_cpublas_vs_Fujimoto_float)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(float_vs.at(atlas_mv) + 3).arg(float_vs.at(Fujimoto_mv) + 3)
 *                 + QString(" title \"CPU BLAS vs Fujimoto (float)\" w p");
 * 
 *     if(this->params.run_cpublas_vs_Fujimoto_double)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(double_vs.at(atlas_mv) + offset).arg(double_vs.at(Fujimoto_mv) + offset)
 *                 + QString(" title \"CPU BLAS vs Fujimoto (double)\" w p");
 * 
 *     if(this->params.run_Fujimoto_vs_cublas_float)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(float_vs.at(Fujimoto_mv) + 3).arg(float_vs.at(cublas_mv) + 3)
 *                 + QString(" title \"Fujimoto vs CUBLAS (float)\" w p");
 * 
 *     if(this->params.run_Fujimoto_vs_cublas_double)
 *         gpplots_speedup += ((gpplots_speedup.isEmpty()) ? QString("") : QString(", "))
 *                 + QString("\"../MVTest_results.out\" using (1*2):(%1 / %2)")
 *                 .arg(double_vs.at(Fujimoto_mv) + offset).arg(double_vs.at(cublas_mv) + offset)
 *                 + QString(" title \"Fujimoto vs CUBLAS (double)\" w p");
 * 
 *     gnuplot += gpplots_speedup;
 * 
 *     gnuplot += "\n!ps2pdf runtimes.ps runtimes.pdf";
 *     gnuplot += "\n!rm runtimes.ps";
 *     gnuplot += "\n!ps2pdf speedup.ps speedup.pdf";
 *     gnuplot += "\n!rm speedup.ps";
 * 
 * 
 *     std::cout << "Results are processed and saved.\n";
 * 
 *     this->save_results();
 * 
 *      QDir cwd = QDir::current();
 *      QString plot_dir = this->params.run_dir + "/plot";
 *              cwd.mkpath("./plot");
 * 
 *      QDir::setCurrent(plot_dir);
 * 
 * 
 *     QFile plotscript("plot.gp");
 * 
 *     bool success = plotscript.open(QIODevice::WriteOnly);
 *     if (!success)
 *         std::cerr << "Opening gnuplot file failed!" << std::endl;
 * 
 *     plotscript.write(gnuplot.toStdString().c_str());
 * 
 *     plotscript.close();
 * 
 *     if (! plotscript.exists() )
 *         std::cerr << "Writing gnuplot file failed!" << std::endl;
 * 
 * 
 *     FILE *gp = popen("gnuplot -persist", "w");
 *     fprintf(gp, "load \"plot.gp\"\n");
 *     fflush(gp);
 *     pclose(gp);
 * 
 * 
 *     QDir::setCurrent(this->params.run_dir);
 * 
 *     std::cout << "Finished." << std::endl;
 * }
 * 
@endcode
 <a name="plain-Functionsave_results"></a>
@code
 * void step2::MyFancySimulation::save_results()
 * {
 *     std::string filename("MVTest_results");
 * 
 *     filename += ".out";
 * 
 *     std::ofstream out(filename.c_str());
 * 
 *     out << "# max n_cols  : " << this->params.max_n_cols << std::endl
 *         << "# min n_cols  : " << this->params.min_n_cols << std::endl
 *         << "# growth rate : " << this->params.n_rows_growth_rate << std::endl
 *         << std::endl;
 * 
 *     results_table.write_text(out);
 * }
 * 
 * #endif
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef SimUIParams_H
 * #define SimUIParams_H
 * 
 * 
 * #include <QString>
 * #include <deal.II/base/parameter_handler.h>
 * 
 * namespace step2 {
 * 
@endcode
 <a name="plain-EnumMVCase"></a>
@code
 * enum MVCase { Fujimoto_mv, atlas_mv, cublas_mv, none / * for future use : , openmp_mv, ...* / };
 * 
@endcode
 <a name="plain-structSimUIParams"></a>
@code
 * struct SimUIParams {
 * 
 *     SimUIParams() {}
 * 
 *     static void declare(dealii::ParameterHandler & prm);
 * 
 *     void get(dealii::ParameterHandler & prm);
 * 
 *     bool
 *     run_cpublas_vs_cublas_float,
 *     run_cpublas_vs_cublas_double,
 *     run_cpublas_vs_Fujimoto_float,
 *     run_cpublas_vs_Fujimoto_double,
 *     run_Fujimoto_vs_cublas_float,
 *     run_Fujimoto_vs_cublas_double;
 * 
 *     int fj_version;
 * 
 *     QString run_dir;
 * 
 *     std::vector<MVCase> float_tests, double_tests;
 *     std::map<MVCase, int> float_vs, double_vs;
 * 
 * private:
 *     SimUIParams (const SimUIParams & / *other* /) {}
 * 
 *     SimUIParams & operator = (const SimUIParams & / *other* /) { return *this; }
 * };
 * 
 * }
 * #endif // SimUIParams_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVTESTUIPARAMS_H
 * #define MVTESTUIPARAMS_H
 * 
 * #include <step-2/SimUIParams.h>
 * #include <step-2/DeviceParams.h>
 * #include <step-2/MVMultDriverInterface.h>
 * 
 * namespace step2 {
 * 
@endcode
 <a name="plain-ClassTestUIParamsBase"></a>
@code
 * struct TestUIParamsBase {
 * 
 *     TestUIParamsBase() {}
 * 
 *     static void declare(dealii::ParameterHandler & prm);
 * 
 *     void get(dealii::ParameterHandler & prm);
 * 
 *     int  min_n_cols;
 *     int  max_n_cols;
 * 
 *     double n_rows_growth_rate;
 * 
 *     int n_repetitions;
 * 
 * 
 * private:
 *     TestUIParamsBase(const TestUIParamsBase & ) {}
 * 
 *     TestUIParamsBase & operator = (const TestUIParamsBase & / *other* /)
 *     {
 *         return *this;
 *     }
 * };
 * 
 * 
@endcode
 <a name="plain-ClassMVTestUIParams"></a>
@code
 * struct MVTestUIParams
 *         :
 *         public SimUIParams,
 *         public DeviceParams,
 *         public TestUIParamsBase
 * {
 *     MVTestUIParams()
 *         :
 *           SimUIParams(),
 *           DeviceParams(),
 *           TestUIParamsBase()
 *     {}
 * 
 *     static void declare(dealii::ParameterHandler & prm);
 * 
 *     void get(dealii::ParameterHandler & prm);
 * 
 * 
 *     int n_random_trials;
 * 
 *     std::vector<step2::matrixSize> matrix_sizes;
 * 
 * protected:
 *     void create_random_matrix_sizes();
 *     void create_regular_matrix_sizes();
 * 
 * private:
 *     MVTestUIParams (const MVTestUIParams & / *other* /)
 *         :
 *           SimUIParams(),
 *           DeviceParams(),
 *           TestUIParamsBase()
 *     {}
 * 
 *     MVTestUIParams & operator = (const MVTestUIParams & / *other* /)
 *     {
 *         return *this;
 *     }
 * };
 * 
 * }
 * #endif // MVTESTUIPARAMS_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVTEST_H
 * #define MVTEST_H
 * 
 * #include <QDir>
 * #include <step-2/Fujimoto_driver_step-2.h>
 * #include <step-2/cuda_driver_step-2.h>
 * #include <step-2/CpuBlas_driver_step-2.h>
 * #include <step-2/MVTestUIParams.h>
 * 
 * #include <deal.II/base/convergence_table.h>
 * 
 * namespace step2 {
 * 
@endcode
 <a name="plain-ClassMVTest"></a>
@code
 * template <typename T>
 * class MVTest {
 * 
 * public:
 *     typedef ::FullMatrixAccessor<T> FullMatrixAccessor;
 * 
 *     MVTest(const MVTestUIParams & p,
 *            dealii::ConvergenceTable & results_table,
 *            MVCase variant=atlas_mv);
 * 
 *     ~MVTest();
 * 
 *     virtual QString run();
 * 
 * 
 * protected:
 *     typename step2::MVMultDriverInterface<T> * driver_m;
 * 
 *     virtual void setup_and_assemble(unsigned int nr,
 *                                     unsigned int nc);
 * 
 *     const MVTestUIParams * params;
 * 
 *     FullMatrixAccessor A;
 * 
 *     dealii::Vector<T> x_orig, y_orig;
 * 
 *     std::string col_head;
 * 
 *     dealii::ConvergenceTable & results_table;
 * };
 * }
 * #endif // MVTEST_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVTEST_HH
 * #define MVTEST_HH
 * 
 * #include <step-2/MVTest.h>
 * #include <step-2/PrecisionName.h>
 * #include <deal.II/base/convergence_table.h>
 * 
@endcode
 <a name="plain-Constructor"></a>
@code
 * template <typename T>
 * step2::MVTest<T>::MVTest(const step2::MVTestUIParams & p,
 *                          dealii::ConvergenceTable &rt,
 *                          MVCase mv_variant)
 *     :
 *       params(&p),
 *       results_table(rt)
 * {
 *     driver_m = NULL;
 * 
 *     switch (mv_variant) {
 * 
 *     case Fujimoto_mv:
 *         driver_m = new FujimotoDriver<T,cublas> (this->params->fj_version);
 *         col_head = "Fujimoto " + QString::number(this->params->fj_version).toStdString();
 *         break;
 *     case cublas_mv:
 *         driver_m = new CUBlasDriver<T,cublas> ();
 *         col_head  = "CUBLAS";
 *         break;
 *     case atlas_mv:
 *         driver_m = new step2::CpuBlasDriver<T,blas> ();
 *         col_head  = "CPU Blas";
 *         break;
 *     default: // do nothing
 *         break;
 *     }
 * 
 *     if (mv_variant != none)
 *     {
 *         assert(driver_m);
 * 
 *         col_head += " " + PrecisionName<T>::name();
 * 
 *         std::cerr << "\nTesting " << col_head.c_str() << " mvmult "
 *                   << std::endl;
 *     }
 * }
 * 
@endcode
 <a name="plain-Destructor"></a>
@code
 * template <typename T>
 * step2::MVTest<T>::~MVTest()
 * {
 *     if (driver_m)
 *         delete driver_m;
 * }
 * 
 * 
@endcode
 <a name="plain-Functionrun"></a>
@code
 * template <typename T>
 * QString
 * step2::MVTest<T>::run()
 * {
 *     for (size_t i=0; i< this->params->matrix_sizes.size(); i++)
 *     {
 *         size_t nr = this->params->matrix_sizes[i].first ;
 *         size_t nc = this->params->matrix_sizes[i].second;
 * 
 * #ifdef DEBUG
 *         std::cout  << "Testing MV for " << nr << "x" << nc << " matrix" << std::endl;
 * #endif
 *         setup_and_assemble(nr, nc);
 * 
 * 
 *         std::vector<T> x(this->x_orig.begin(), this->x_orig.end());
 * 
 *         unsigned int n_elements =  this->y_orig.size();
 *         std::vector<T> y(n_elements, 0.);
 * 
 *         double elapsed_time
 *                 =
 *                 driver_m->mvmult(y, A, x,
 *                                  this->params->n_repetitions) / this->params->n_repetitions;
 * 
 * 
 *         dealii::Vector<T> diff ( n_elements );
 *         for (unsigned int i = 0; i < n_elements; i++)
 *             diff(i) = (y[i] - y_orig(i)) / y_orig(i);
 * 
 *         double linfty_error = diff.linfty_norm();
 * 
 *         if (linfty_error> (sizeof(T)<8 ? 1e-5 : 1e-14))
 *         {
 *             std::cerr << nr << "x" << nc << " matrix : "
 *                       << "|| (y - y_orig)/y_orig||_infty = " << linfty_error
 *                       << " MVTest probably failed!"
 *                       << std::endl;
 * 
 *             if (y.size() < 20) {
 *                 std::cerr << y_orig << std::endl;
 * 
 *                 std::copy(y.begin(), y.end(), diff.begin());
 *                 std::cerr << diff << std::endl;
 *             }
 *         }
 * 
 *         this->results_table.add_value(col_head.c_str(), elapsed_time);
 * 
 *         this->results_table.set_precision(col_head.c_str(), 12);
 *     }
 * 
 *     return col_head.c_str();
 * }
 * 
 * 
@endcode
 <a name="plain-Functionsetup_and_assemble"></a>
@code
 * template <typename T>
 * void
 * step2::MVTest<T>::setup_and_assemble(unsigned int nr, unsigned int nc)
 * {
 *     this->A.reinit(nr, nc);
 *     this->x_orig.reinit(nc);
 *     this->y_orig.reinit(nr);
 * 
 *     y_orig = 0.;
 *     int tmp = 1;
 *     for (unsigned int r = 0; r < nr; ++r)
 *         for (unsigned int c = 0; c < nc; ++c)
 *         {
 *             x_orig(c)  = (c+1);
 *             A(r,c)     = tmp; tmp++;//r+1 + 1./(c+1);
 *             y_orig(r) +=  A(r,c)*x_orig(c);
 *         }
 * }
 * #endif
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef MVMultDriverInterface_H
 * #define MVMultDriverInterface_H
 * 
 * #include <vector>
 * #include <numeric>
 * #include <lac/blas++.h>
 * 
 * namespace step2 {
 * 
 * typedef    std::pair<size_t, size_t> matrixSize;
 * 
@endcode
 <a name="plain-ClassMVMultDriverInterface"></a>
@code
 * template<typename Number>
 * class MVMultDriverInterface {
 * 
 * public:
 * 
 *     typedef ::FullMatrixAccessor<Number> FullMatrixAccessor;
 * 
 *     MVMultDriverInterface()	{}
 * 
 *     virtual ~MVMultDriverInterface () {}
 * 
@endcode
 <a name="plain-Functionmvmult"></a>
@code
 *     virtual double mvmult(std::vector<Number> & y,
 *                           const FullMatrixAccessor & A,
 *                           const std::vector<Number> & x,
 *                           int n_repetitions) = 0;
 * };
 * 
 * } // namespace step2 END
 * #endif // MVMultDriverInterface_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CPUBLAS_DRIVER_STEP2_H
 * #define CPUBLAS_DRIVER_STEP2_H
 * 
 * #include <vector>
 * #include <lac/blas++.h>
 * #include <step-2/MVMultDriverInterface.h>
 * 
 * namespace step2 {
 * 
@endcode
 <a name="plain-ClassCpuBlasDriver"></a>
@code
 * template<typename EntryType, typename blasType>
 * class CpuBlasDriver : public MVMultDriverInterface<EntryType>
 * {
 * public:
 * 
 *     typedef
 *     typename MVMultDriverInterface< EntryType>::FullMatrixAccessor
 *     FullMatrixAccessor;
 * 
 *     CpuBlasDriver() {}
 * 
 *     virtual ~CpuBlasDriver () {}
 * 
 *     virtual double mvmult(std::vector<EntryType>& y,
 *                           const FullMatrixAccessor& A,
 *                           const std::vector<EntryType>& x,
 *                           int n_repetitions);
 * };
 * 
 * } // namespace step2 END
 * 
 * #include <step-2/CpuBlas_driver_step-2.hh>
 * #endif // CPUBLAS_DRIVER_STEP2_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CPUBLAS_DRIVER_STEP_2_HH
 * #define CPUBLAS_DRIVER_STEP_2_HH
 * 
 * #include <base/CUDATimer.h>
 * 
@endcode
 <a name="plain-Functionmvmult"></a>
@code
 * template<typename EntryType,typename blasType>
 * double step2::CpuBlasDriver<EntryType,blasType>::mvmult(std::vector<EntryType>& y,
 *                                                         const FullMatrixAccessor& A,
 *                                                         const std::vector<EntryType>& x,
 *                                                         int n_repetitions)
 * {
 *     int n_rows = A.n_rows();
 *     int n_cols = A.n_cols();
 * 
 *     EntryType * d_y = &y[0];
 * 
 *     EntryType * d_A = const_cast<FullMatrixAccessor &>(A).val();
 * 
 *     EntryType * d_x = &const_cast<std::vector<EntryType> &>(x)[0];
 * 
 *     EntryType alpha = 1;
 *     EntryType beta  = 1;
 * 
 *     int incx = 1; int incy = 1;
 * 
 *     int lda = n_cols;
 * 
 *     int m = n_cols;
 *     int n = n_rows;
 * 
 *     double cumulative_runtime = 0.;
 *     for (int i=0; i<n_repetitions; i++)
 *     {
 *         for (unsigned int k = 0; k < n_rows; k++)
 *             d_y[k] = 0.;
 * 
 *         CUDATimer timer;
 * 
 *         blasType::gemv ('t', m, n, alpha,
 *                         d_A, lda,
 *                         d_x, incx,
 *                         beta,
 *                         d_y, incy);
 * 
 *         timer.stop();
 *         cumulative_runtime += timer.elapsed();
 *     }
 * 
 *     return cumulative_runtime;
 * }
 * #endif // CPUBLAS_DRIVER_STEP_2_HH
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CUBlasDriver_STEP_2_H
 * #define CUBlasDriver_STEP_2_H
 * 
 * #include <vector>
 * #include <lac/blas++.h>
 * #include <step-2/MVMultDriverInterface.h>
 * 
 * namespace step2 {
 * 
@endcode
 <a name="plain-ClassCUBlasDriver"></a>
@code
 * template<typename T,typename blasType=cublas>
 * class CUBlasDriver : public MVMultDriverInterface<T>
 * {
 * public:
 *     typedef
 *     typename MVMultDriverInterface<T>::FullMatrixAccessor
 *     FullMatrixAccessor;
 * 
 * 
 *     CUBlasDriver();
 * 
 *     virtual ~CUBlasDriver ();
 * 
 *     virtual double mvmult(std::vector<T>& y,
 *                           const FullMatrixAccessor& A,
 *                           const std::vector<T>& x,
 *                           int	n_repetitions);
 * };
 * 
 * } // namespace step2 END
 * 
 * #include <step-2/cuda_driver_step-2.hh>
 * #endif // CUBlasDriver_STEP_2_H
 * 
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CUDA_DRIVER_STEP_2_HH
 * #define CUDA_DRIVER_STEP_2_HH
 * 
 * #include <base/CUDATimer.h>
 * 
@endcode
 <a name="plain-ConstructorCUBlasDriver"></a>
@code
 * template<typename T,typename blasType>
 * step2::CUBlasDriver<T,blasType>::CUBlasDriver() : MVMultDriverInterface<T>()
 * {
 *     blasType::Init();
 * }
 * 
 * 
@endcode
 <a name="plain-DestructorCUBlasDriver"></a>
@code
 * template<typename T,typename blasType>
 * step2::CUBlasDriver<T,blasType>::~CUBlasDriver()
 * {
 *     blasType::Shutdown();
 * }
 * 
 * 
@endcode
 <a name="plain-Functionmvmult"></a>
@code
 * template<typename T,typename blasType>
 * double step2::CUBlasDriver<T,blasType>::mvmult(std::vector<T>& y,
 *                                                const FullMatrixAccessor& A,
 *                                                const std::vector<T>& x,
 *                                                int n_repetitions)
 * {   
 *     int n_rows = A.n_rows();
 *     int n_cols = A.n_cols();
 * 
 *     T * dst = &y[0];
 * 
 *     T * A_entries = const_cast<FullMatrixAccessor &>(A).val();
 * 
 *     T * src = &const_cast<std::vector<T> &>(x)[0];
 * 
 *     T alpha=1.;
 *     T beta=1.;
 *     int incx=1;
 *     int incy=1;
 * 
 *     int lda=n_cols;
 *     int m = n_cols;
 *     int n = n_rows;
 * 
 *     T *d_A, *d_x, *d_y;
 * 
 *     cudaMalloc((void **) &d_A, n_rows * n_cols * sizeof(T));
 * 
 *     cudaMalloc((void **) &d_x, n_cols * sizeof(T));
 *     cudaMalloc((void **) &d_y, n_rows * sizeof(T));
 * 
 *     cudaMemcpy(d_x, src, n_cols * sizeof(T), cudaMemcpyHostToDevice);
 * 
 *     cudaMemcpy(d_A, A_entries, n_rows * n_cols * sizeof(T), cudaMemcpyHostToDevice);
 * 
 *     double cumulative_runtime = 0.;
 *     for (int i=0; i<n_repetitions; i++)
 *     {
 *         cudaThreadSynchronize();
 *         CUDATimer timer;
 * 
 *         cudaMemcpy(d_y, dst, n_rows * sizeof(T), cudaMemcpyHostToDevice);
 * 
 *         blasType::gemv ('t', m, n, alpha,
 *                         d_A, lda,
 *                         d_x,  incx,
 *                         beta,
 *                         d_y,  incy);
 * 
 *         cudaThreadSynchronize();
 *         timer.stop();
 *         cumulative_runtime += timer.elapsed();
 *     }
 * 
 *     cudaMemcpy(dst, d_y, n_rows * sizeof(T), cudaMemcpyDeviceToHost);
 * 
 *     cudaFree(d_y);
 *     cudaFree(d_x);
 *     cudaFree(d_A);
 * 
 *     return cumulative_runtime;
 * }
 * #endif // CUDA_DRIVER_STEP_2_HH
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef FUJIMOTO_DRIVER_step2_H
 * #define FUJIMOTO_DRIVER_step2_H
 * 
 * #include <vector>
 * #include <lac/blas++.h>
 * #include <step-2/MVMultDriverInterface.h>
 * #include <step-2/cuda_kernel_wrapper_step-2.cu.h>
 * 
 * namespace step2 {
 * 
@endcode
 <a name="plain-ClassFujimotoDriver"></a>
@code
 * template<typename T,typename blasType=cublas>
 * class FujimotoDriver : public MVMultDriverInterface<T>, private Kernels<T>
 * {
 * public:
 *     typedef
 *     typename MVMultDriverInterface<T>::FullMatrixAccessor FullMatrixAccessor;
 * 
 *     FujimotoDriver(const int v) : fj_version(v) {}
 * 
 *     virtual  ~FujimotoDriver () {}
 * 
 *     virtual double mvmult(std::vector<T>& y,
 *                           const FullMatrixAccessor& A,
 *                           const std::vector<T>& x,
 *                           int n_repetitions);
 * 
 * protected:
 *     const int fj_version;
 * };
 * 
 * } // namespace step2 END
 * 
 * #include <step-2/Fujimoto_driver_step-2.hh>
 * #endif // FUJIMOTO_DRIVER_step2_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef FUJIMOTO_DRIVER_step2_HH
 * #define FUJIMOTO_DRIVER_step2_HH
 * 
 * #include <step-2/cuda_kernel_wrapper_step-2.cu.h>
 * #include <base/CUDATimer.h>
 * 
@endcode
 <a name="plain-Functionmvmult"></a>
@code
 * template<typename Number,typename blasType>
 * double step2::FujimotoDriver<Number,blasType>::mvmult(std::vector<Number> & y,
 *                                                       const FullMatrixAccessor& A,
 *                                                       const std::vector<Number> & x,
 *                                                       int n_repetitions)
 * {
 *     int n_rows = A.n_rows();
 *     int n_cols = A.n_cols();
 * 
 *     Number * dst = &y[0];
 * 
 *     const Number * A_entries = A.val();
 * 
 *     const Number * src = &x[0];
 * 
 * 
 *     double cumulative_elapsed_time = 0;
 * 
 *     this->mv_fujimoto(dst, A_entries, src,
 *                       n_rows, n_cols,
 *                       n_repetitions,
 *                       this->fj_version,
 *                       cumulative_elapsed_time);
 * 
 *     return cumulative_elapsed_time;
 * }
 * 
 * #endif // FUJIMOTO_DRIVER_step2_HH
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * #ifndef CUDA_KERNEL_STEP_2_CU_H
 * #define CUDA_KERNEL_STEP_2_CU_H
 * 
@endcode
 <a name="plain-DeclarationofCUDAInterface"></a>
@code
 * namespace step2 {
 * 
 * 
@endcode
 <a name="plain-ClassKernels"></a>
@code
 * template<typename T>
 * struct Kernels {
 * 
 *     void mv_fujimoto(T *y, const T *A, const T *x,
 *                      const int m, const int n,
 *                      const int n_repetitions, const int fj_version, double& elapsed_time);
 * };
 * }
 * #endif // CUDA_KERNEL_STEP_2_CU_H
 * 
 * 
 * 
 * / *This file is part of SciPAL.
 * 
 *     SciPAL is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU Lesser General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     SciPAL is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU Lesser General Public License for more details.
 * 
 *     You should have received a copy of the GNU Lesser General Public License
 *     along with SciPAL.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright  S. C. Kramer , J. Hagemann  2010 - 2014
 * * /
 * 
 * 
 * 
 * #include <step-2/cuda_kernel_wrapper_step-2.cu.h>
 * 
 * 
 * #ifndef DONT_USE_CUDATIMER
 * #include <base/CUDATimer.h>
 * #endif
 * 
 * #include <stdio.h>
 * 
@endcode
 <a name="plain-Kernels"></a>
@code
 * namespace step2 {
 * 
 * #define bx blockIdx.x
 * #define tx threadIdx.x
 * #define ty threadIdx.y
 * 
 * 
 * texture<float4, 2, cudaReadModeElementType> fTexRefA;
 * 
@endcode
 <a name="plain-Kernel_mv_fujimoto"></a>
@code
 * __global__
 * void
 * _mv_fujimoto(float* y, cudaArray* A, float* x, int m, int n)
 * {
 *     __shared__ float xs[16][16];
 * 
 *     __shared__ float Ps[16][16];
 * 
 *     float4 a;
 * 
 *     float *Psptr = (float *) Ps + (ty << 4) + tx;
 *     int ay = (bx << 4) + ty;
 *     float *xptr = x + (ty << 4) + tx;
 *     float *xsptr = (float *) xs + (tx << 2);
 * 
 *     *Psptr = 0.0f;
 * 
 *     int i;
 *     for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *     {
 *         xs[ty][tx] = *xptr;
 *         __syncthreads();
 * 
 *         int ax = tx + (i >> 2);
 * 
 *         a = tex2D(fTexRefA, ax     , ay);
 *         *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 *         a = tex2D(fTexRefA, ax + 16, ay);
 *         *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *         a = tex2D(fTexRefA, ax + 32, ay);
 *         *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *         a = tex2D(fTexRefA, ax + 48, ay);
 *         *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *         __syncthreads();
 *     }
 * 
 *     if (i + (ty << 4) + tx < n) {
 *         xs[ty][tx] = *xptr;
 *     }
 *     __syncthreads();
 * 
 *     int j;
 *     for (j = 0; j < ((n - i) >> 6); j++, xsptr += 61) {
 *         a = tex2D(fTexRefA, tx + (i >> 2) + (j << 4), ay);
 *         *Psptr += a.x * *xsptr++ + a.y * *xsptr++ + a.z * *xsptr++ + a.w * *xsptr;
 *     }
 *     __syncthreads();
 * 
 *     int remain = (n - i) & 63;
 * 
 *     if ((tx << 2) < remain) {
 *         a = tex2D(fTexRefA, tx + (i >> 2) + (j << 4), ay);
 *         *Psptr += a.x * *xsptr++;
 *     }
 *     if ((tx << 2) + 1 < remain) *Psptr += a.y * *xsptr++;
 *     if ((tx << 2) + 2 < remain) *Psptr += a.z * *xsptr++;
 *     if ((tx << 2) + 3 < remain) *Psptr += a.w * *xsptr;
 *     __syncthreads();
 * 
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 *     __syncthreads();
 * 
 *     if (ty == 0 && (bx << 4) + tx < m) y[(bx << 4) + tx] = Ps[tx][0];
 * }
 * 
 * 
 * 
@endcode
 <a name="plain-Kernel_mv_fujimoto_T"></a>
@code
 * template<typename T>
 * struct IsFloat;
 * 
 * template<>
 * struct IsFloat<float>
 * {
 *     static const bool value = true;
 * };
 * 
 * template<typename T>
 * struct IsFloat
 * {
 *     static const bool value = false;
 * };
 * 
 * template<typename T>
 * struct TexEl;
 * 
 * template<>
 * struct TexEl<float>
 * {
 *     typedef float4 value_type;
 *     typedef float4 alt_value_type;
 *     typedef float4 texel_type;
 *     static const int tex_stride = 4;
 * };
 * 
 * template<>
 * struct TexEl<double>
 * {
 *     typedef double4 value_type;
 *     typedef double2 alt_value_type;
 *     typedef int4 texel_type;
 *     static const int tex_stride = 2;
 * };
 * 
 * texture<TexEl<double>::texel_type, 2, cudaReadModeElementType> dTexRefA;
 * 
 * 
 * template<typename T>
 * struct texAccessor {
 * 
 *     __device__
 *     typename TexEl<T>::value_type
 *     operator() (int ax, int ay);
 * 
 * };
 * 
 * template<>
 * TexEl<float>::value_type texAccessor<float>::operator() (int ax, int ay)
 * {
 *     return tex2D(fTexRefA, ax, ay);
 * }
 * 
 * template<>
 * TexEl<double>::value_type texAccessor<double>::operator() (int ax, int ay)
 * {
 *     TexEl<double>::texel_type tmp;
 *     TexEl<double>::value_type a;
 * 
 *     tmp = tex2D(dTexRefA, 2*ax, ay);
 *     a.x = __hiloint2double(tmp.y, tmp.x);
 *     a.y = __hiloint2double(tmp.w, tmp.z);
 * 
 *     tmp = tex2D(dTexRefA, 2*ax+1, ay);
 *     a.z = __hiloint2double(tmp.y, tmp.x);
 *     a.w = __hiloint2double(tmp.w, tmp.z);
 * 
 * #ifndef nDEBUG
 *     printf("a : %f, %f, %f, %f\n", a.x, a.y, a.z, a.w);
 * #endif
 *     return a;
 * }
 * 
 * template<typename T>
 * __global__
 * void
 * _mv_fujimoto_T( T* y, cudaArray* A, T* x, int m, int n)
 * {
 *     __shared__ T xs[16][16];
 * 
 *     __shared__ T Ps[16][16];
 * 
 *     typename TexEl<T>::value_type a;
 * 
 *     T *Psptr = (T *) Ps + (ty << 4) + tx;
 * 
 *     int ay = (bx << 4) + ty;
 * 
 *     T *xptr = x + (ty << 4) + tx;
 *     T *xsptr = (T *) xs + (tx << 2);
 * 
 *     *Psptr = 0.0f;
 *     int i;
 * 
 *     texAccessor<T> tex_2D;
 * 
 *     for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *     {
 *         xs[ty][tx] = *xptr;
 *         __syncthreads();
 * 
 *         int ax = tx + (i >> 2);
 * 
 *         a = tex_2D(ax, ay);
 *         *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 *         a = tex_2D(ax+16, ay);
 *         *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *         a = tex_2D(ax+32, ay);
 *         *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *         a = tex_2D(ax+48, ay);
 *         *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *         __syncthreads();
 *     }
 * 
 *     if (i + (ty << 4) + tx < n) {
 *         xs[ty][tx] = *xptr;
 *     }
 *     __syncthreads();
 * 
 *     int j;
 *     for (j = 0; j < ((n - i) >> 6); j++, xsptr += 61) {
 *         a = tex_2D(tx + (i >> 2) + (j << 4), ay);
 *         *Psptr += a.x * *xsptr++ + a.y * *xsptr++    +     a.z * *xsptr++ + a.w * *xsptr;
 *     }
 *     __syncthreads();
 * 
 *     int remain = (n - i) & 63;
 *     if ((tx << 2) < remain) {
 *         a = tex_2D(tx + (i >> 2) + (j << 4), ay);
 * 
 *         *Psptr += a.x * *xsptr++;
 *     }
 *     if ((tx << 2) + 1 < remain) *Psptr += a.y * *xsptr++;
 *     if ((tx << 2) + 2 < remain) *Psptr += a.z * *xsptr++;
 *     if ((tx << 2) + 3 < remain) *Psptr += a.w * *xsptr;
 *     __syncthreads();
 * 
 * 
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 * 
 *     __syncthreads();
 *     if (ty == 0 && (bx << 4) + tx < m) y[(bx << 4) + tx] = Ps[tx][0];
 * }
 * 
 * 
@endcode
 <a name="plain-Kernel_mv_fujimoto_T2"></a>
@code
 * template<typename T>
 * __global__
 * void
 * _mv_fujimoto_T2( T* y, cudaArray* A, T* x, int m, int n)
 * {
 *     __shared__ T xs[16][16];
 * 
 *     __shared__ T Ps[16][16];
 * 
 *     typename TexEl<T>::value_type a;
 * 
 *     T *Psptr = (T *) Ps + (16*ty) + tx;
 * 
 *     int ay = (16*bx) + ty;
 * 
 *     T *xptr = x + (16*ty) + tx;
 *     T *xsptr = (T *) xs + (4*tx);
 * 
 *     *Psptr = 0.0f;
 *     int i;
 * 
 *     texAccessor<T> tex_2D;
 * 
 * 
 *     for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *     {
 *         xs[ty][tx] = *xptr;
 *         __syncthreads();
 * 
 *         int ax = tx + (i/4);
 * 
 *         a = tex_2D(ax, ay);
 *         *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 *         a = tex_2D(ax+16, ay);
 *         *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *         a = tex_2D(ax+32, ay);
 *         *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *         a = tex_2D(ax+48, ay);
 *         *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *         __syncthreads();
 *     }
 * 
 *     if (i + (16*ty) + tx < n) {
 *         xs[ty][tx] = *xptr;
 *     }
 *     __syncthreads();
 * 
 *     int j;
 *     for (j = 0; j < ((n - i)/64); j++, xsptr += 61) {
 *         a = tex_2D(tx + (i/4) + (16*j), ay);
 *         *Psptr += a.x * *xsptr++ + a.y * *xsptr++    +     a.z * *xsptr++ + a.w * *xsptr;
 *     }
 *     __syncthreads();
 * 
 *     int remain = (n - i) & 63;
 *     if ((4*tx) < remain) {
 *         a = tex_2D(tx + (i/4) + (16*j), ay);
 * 
 *         *Psptr += a.x * *xsptr++;
 *     }
 *     if ((4*tx) + 1 < remain) *Psptr += a.y * *xsptr++;
 *     if ((4*tx) + 2 < remain) *Psptr += a.z * *xsptr++;
 *     if ((4*tx) + 3 < remain) *Psptr += a.w * *xsptr;
 *     __syncthreads();
 * 
 * 
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 * 
 *     __syncthreads();
 *     if (ty == 0 && (16*bx) + tx < m) y[(16*bx) + tx] = Ps[tx][0];
 * }
 * 
 * 
@endcode
 <a name="plain-Kernel_mv_fujimoto_T3"></a>
@code
 * template<typename T>
 * struct texAccessorOpt {
 * 
 *     __device__
 *     typename TexEl<T>::alt_value_type
 *     operator() (int ax, int ay);
 * 
 * };
 * 
 * template<>
 * TexEl<float>::alt_value_type texAccessorOpt<float>::operator() (int ax, int ay)
 * {
 *     return tex2D(fTexRefA, ax, ay);
 * }
 * 
 * template<>
 * TexEl<double>::alt_value_type texAccessorOpt<double>::operator() (int ax, int ay)
 * {
 *     TexEl<double>::texel_type tmp;
 *     TexEl<double>::alt_value_type a;
 * 
 *     tmp = tex2D(dTexRefA, ax, ay);
 *     a.x = __hiloint2double(tmp.y, tmp.x);
 *     a.y = __hiloint2double(tmp.w, tmp.z);
 * 
 * #ifdef DEBUG
 *     printf("a : %f, %f\n", a.x, a.y);
 * #endif
 *     return a;
 * }
 * 
 * template<typename T>
 * __global__
 * void
 * _mv_fujimoto_T3( T* y, cudaArray* A, T* x, int m, int n)
 * {
 *     __shared__ T xs[16][16];
 * 
 *     __shared__ T Ps[16][16];
 * 
 * 
 *     T *Psptr = (T *) Ps + (16*ty) + tx;
 * 
 *     int ay = (16*bx) + ty;
 * 
 *     T *xptr = x + (16*ty) + tx;
 * 
 * 
 *     *Psptr = 0.0f;
 *     int i;
 * 
 *     if(IsFloat<T>::value==true)
 *     {
 *         T *xsptr = (T *) xs + (4*tx);
 *         typename TexEl<T>::value_type a;
 *         texAccessor<T> tex_2D;
 *         for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *         {
 *             xs[ty][tx] = *xptr;
 *             __syncthreads();
 * 
 *             int ax = tx + (i/4);
 * 
 *             a = tex_2D(ax, ay);
 *              printf("a : %f, %f, %f, %f\n", a.x, a.y, a.z, a.w);
 *             *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1) + a.z * *(xsptr +   2) + a.w * *(xsptr +   3);
 * 
 *             a = tex_2D(ax+16, ay);
 *             *Psptr += a.x * *(xsptr +  64) + a.y * *(xsptr +  65) + a.z * *(xsptr +  66) + a.w * *(xsptr +  67);
 * 
 *             a = tex_2D(ax+32, ay);
 *             *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129) + a.z * *(xsptr + 130) + a.w * *(xsptr + 131);
 * 
 *             a = tex_2D(ax+48, ay);
 *             *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193) + a.z * *(xsptr + 194) + a.w * *(xsptr + 195);
 * 
 *             __syncthreads();
 *         }
 * 
 *         if (i + (16*ty) + tx < n) {
 *             xs[ty][tx] = *xptr;
 *         }
 *         __syncthreads();
 * 
 * 
 *         int j;
 *         for (j = 0; j < ((n - i)/64); j++, xsptr += 61) {
 *             a = tex_2D(tx + (i/4) + (16*j), ay);
 *             *Psptr += a.x * *xsptr++ + a.y * *xsptr++ + a.z * *xsptr++ + a.w * *xsptr;
 *         }
 *         __syncthreads();
 * 
 * 
 *         int remain = (n - i) & 63;
 *         if ((4*tx) < remain) {
 *             a = tex_2D(tx + (i/4) + (16*j), ay);
 * 
 *             *Psptr += a.x * *xsptr++;
 *         }
 *         if ((4*tx) + 1 < remain) *Psptr += a.y * *xsptr++;
 *         if ((4*tx) + 2 < remain) *Psptr += a.z * *xsptr++;
 *         if ((4*tx) + 3 < remain) *Psptr += a.w * *xsptr;
 *         __syncthreads();
 *     }
 *     else {
 *         T *xsptr = (T *) xs + (2*tx);
 * 
 *         typename TexEl<T>::alt_value_type a;
 * 
 *         texAccessorOpt<T> tex_2D;
 * 
 *         for (i = 0; i < (n & ~255); i += 256, xptr += 256)
 *         {
 *             xs[ty][tx] = *xptr;
 * 
 *             __syncthreads();
 * 
 *             int ax = tx + (i/2);
 * 
 * 
 *             a = tex_2D(ax, ay);
 *             *Psptr += a.x * *xsptr         + a.y * *(xsptr +   1);
 * 
 *             a = tex_2D(ax+16, ay);
 *             *Psptr += a.x * *(xsptr +  32) + a.y * *(xsptr +  33);
 * 
 *             a = tex_2D(ax+32, ay);
 *             *Psptr += a.x * *(xsptr + 64) + a.y * *(xsptr + 65);
 * 
 *             a = tex_2D(ax+48, ay);
 *             *Psptr += a.x * *(xsptr + 96) + a.y * *(xsptr + 97);
 * 
 *             a = tex_2D(ax+64, ay);
 *             *Psptr += a.x * *(xsptr + 128) + a.y * *(xsptr + 129);
 * 
 *             a = tex_2D(ax+80, ay);
 *             *Psptr += a.x * *(xsptr + 160) + a.y * *(xsptr + 161);
 * 
 *             a = tex_2D(ax+96, ay);
 *             *Psptr += a.x * *(xsptr + 192) + a.y * *(xsptr + 193);
 * 
 *             a = tex_2D(ax+112, ay);
 *             *Psptr += a.x * *(xsptr + 224) + a.y * *(xsptr + 225);
 * 
 *             __syncthreads();
 *         }
 * 
 *         if (i + (16*ty) + tx < n) xs[ty][tx] = *xptr;
 * 
 *         __syncthreads();
 * 
 * 
 *         int j;
 * 
 *         for (j = 0; j < ((n - i)/32); j++, xsptr += 31)
 *         {
 *             a = tex_2D(tx + (i/2) + (16*j), ay);
 *             *Psptr += a.x * *xsptr++ + a.y * *xsptr;
 *         }
 *         __syncthreads();
 * 
 * 
 *         int remain = (n - i) & 31;
 * 
 *         if ((2*tx) < remain) {
 *             a = tex_2D(tx + (i/2) + (16*j), ay);
 * 
 *             *Psptr += a.x * *xsptr++;
 *         }
 * 
 *         if ( (2*tx) + 1 < remain)
 *         {
 *             *Psptr += a.y * *xsptr;
 *         }
 * 
 *         __syncthreads();
 *     }
 * 
 *     if (tx < 8) *Psptr += *(Psptr + 8);
 *     if (tx < 4) *Psptr += *(Psptr + 4);
 *     if (tx < 2) *Psptr += *(Psptr + 2);
 *     if (tx < 1) *Psptr += *(Psptr + 1);
 * 
 *     __syncthreads();
 *     if (ty == 0 && (16*bx) + tx < m) y[(16*bx) + tx] = Ps[tx][0];
 * }
 * 
 * 
@endcode
 <a name="plain-Functionmv_fujimoto"></a>
@code
 * void __do_FJ_orig(float* d_y, cudaArray* d_A, float* d_x, int m, int n, dim3 grid, dim3 threads)
 * {
 *     _mv_fujimoto<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 * }
 * 
 * void __do_FJ_orig(double* , cudaArray* , double* , int , int , dim3 , dim3 )
 * {
 *     printf("For double precision the original version of Fujimoto is not available!\n");
 * }
 * 
 * template<typename T>
 * void Kernels<T>::mv_fujimoto(T *y, const T *A, const T *x, const int m, const int n,
 *                              const int n_repetitions,
 *                              const int fj_version,
 *                              double&  elapsed_time)
 * {
 * 
 *     int blkNum = (m + 15)/16; // (m >> 4) + ((m & 15) ? 1 : 0);
 *     int height = blkNum*16; // blkNum << 4;
 * 
 *     int width = 256*((n+255)/256); // (n & 255) ? (((n >> 8) + 1) << 8) : n;
 * 
 *     dim3 threads(16, 16);
 *     dim3 grid(blkNum, 1);
 * 
 *     cudaArray *d_A;
 *     T *d_x, *d_y;
 * 
 *     cudaChannelFormatDesc
 *             channelDesc = cudaCreateChannelDesc<typename TexEl<T>::texel_type/ *float4* />();
 * 
 *     cudaMallocArray(&d_A, &channelDesc, width/TexEl<T>::tex_stride, height);
 * 
 *     size_t size_of_T = sizeof(T);
 * 
 *     cudaMemcpy2DToArray(d_A, 0, 0, A,
 *                         n * size_of_T,
 *                         n * size_of_T,
 *                         m,
 *                         cudaMemcpyHostToDevice);
 * 
 * 
 *     if (IsFloat<T>::value)
 *         cudaBindTextureToArray(fTexRefA, d_A);
 *     else
 *         cudaBindTextureToArray(dTexRefA, d_A);
 * 
 *     cudaMalloc((void **) &d_x, n * size_of_T );
 *     cudaMalloc((void **) &d_y, m * size_of_T );
 * 
 *     cudaMemcpy(d_x, x, n * size_of_T, cudaMemcpyHostToDevice);
 * 
 * #ifndef DONT_USE_CUDATIMER
 *     CUDATimer timer;
 * #endif
 *     for (int i=0; i<n_repetitions; i++)
 *     {
 *         cudaMemcpy(d_y, y, m * size_of_T, cudaMemcpyHostToDevice);
 *         switch (fj_version) {
 *         case 0:
 *             __do_FJ_orig(d_y, d_A, d_x, m, n, grid, threads);
 *             break;
 *         case 1:
 *             _mv_fujimoto_T<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 *             break;
 *         case 2:
 *             _mv_fujimoto_T2<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 *             break;
 *         case 3:
 *             _mv_fujimoto_T3<<< grid, threads >>>(d_y, d_A, d_x, m, n);
 *             break;
 *         default:
 *             break;
 *         }
 *     }
 *     cudaThreadSynchronize();
 * #ifndef DONT_USE_CUDATIMER
 *     timer.stop();
 *     elapsed_time = timer.elapsed() ;
 * #else
 *     elapsed_time = 3.1415926;
 * #endif
 * #ifdef DEBUG
 * #ifndef DONT_USE_CUDATIMER
 *     timer.print_elapsed("Time spent in Fujimotos MV product:");
 * #endif
 * #endif
 * 
 *     cudaMemcpy(y, d_y, m * size_of_T, cudaMemcpyDeviceToHost);
 * 
 *     cudaFree(d_y);
 *     cudaFree(d_x);
 * 
 *     if(IsFloat<T>::value)
 *         cudaUnbindTexture( fTexRefA);
 *     else
 *         cudaUnbindTexture( dTexRefA);
 *     cudaFreeArray(d_A);
 * }
 * 
 * template class Kernels<float>;
 * template class Kernels<double>;
 * 
 * } // namespace step2 END
 * 
 * 
 * 
 * 
 * 
 @endcode
 */
