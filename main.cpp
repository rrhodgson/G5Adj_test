#include <Grid/Grid.h>

using namespace std;
using namespace Grid;

int main (int argc, char ** argv)
{
	Grid_init(&argc,&argv);
	
	auto grid = SpaceTimeGrid::makeFourDimGrid(GridDefaultLatt(), GridDefaultSimd(Nd,vComplexD::Nsimd()),GridDefaultMpi());
	
	Gamma g5(Gamma::Algebra::Gamma5);

	LatticePropagator q(grid);
	q = 1.0;
	
	const auto qD = g5 * adj(q) * g5;
	
	std::cout << "|q|^2          = " << norm2(q) << std::endl;
	std::cout << "|adj(q)|^2     = " << norm2(adj(q)) << std::endl;
	std::cout << "|g5adj(q)g5|^2 = " << norm2(g5*adj(q)*g5) << std::endl;
	std::cout << "|qD|^2         = " << norm2(qD) << std::endl;

	Grid_finalize();
}
