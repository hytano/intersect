
#pragma once

#include <Eigen/Dense>
#include <algorithm>
namespace hytano
{
	// https://www.youtube.com/watch?v=bbTqI0oqL5U

	inline bool intersecting(const Eigen::Vector2d& A, const Eigen::Vector2d& B, const Eigen::Vector2d& C, const Eigen::Vector2d& D) {
		// Calc orientation of C, D with repsect to the line segment AB.
		// Both points C and D need to be of different orientation
		using namespace Eigen;
		auto colinear = [](const Eigen::Vector2d& P, const Eigen::Vector2d& Q, const Eigen::Vector2d& R)->bool {
			using namespace std;
			return (Q.x() <= max(P.x(), R.x()) && Q.x() >= min(P.x(), R.x()) &&
				Q.y() <= max(P.y(), R.y()) && Q.y() >= min(P.y(), R.y()));
		};

		// 0 --> p, q and r are colinear 
		// 1 --> Clockwise 
		// -1 --> Counterclockwise 
		auto orientation = [](const Eigen::Vector2d& P, const Eigen::Vector2d& Q, const Eigen::Vector2d& R)->int
		{
			// See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
			auto val = (Q.y() - P.y()) * (R.x() - Q.x()) - (Q.x() - P.x()) * (R.y() - Q.y());

			if (val == 0.0) {
				return 0;
			} // colinear 

			return (val > 0.0) ? 1 : -1; // clock or counterclock wise 

		};
		
		// Find the four orientations needed for general and 
	// special cases 
		int o1 = orientation(A, B, C);
		int o2 = orientation(A, B, D);
		int o3 = orientation(C, D, A);
		int o4 = orientation(C, D, B);

		// General case 
		if (o1 != o2 && o3 != o4)
			return true;

		// Special Cases 
		// A, B and C are colinear and C lies on segment AB 
		if (o1 == 0 && colinear(A, C, B)) return true;

		// A, B and D are colinear and D lies on segment AB 
		if (o2 == 0 && colinear(A, D, B)) return true;

		// C, D and A are colinear and A lies on segment CD 
		if (o3 == 0 && colinear(C, A, D)) return true;

		// C, D and B are colinear and B lies on segment CD 
		if (o4 == 0 && colinear(C, B, D)) return true;

		return false; // Doesn't fall in any of the above cases 
	}

	class intersect
	{
	public:
		intersect(int init_val) : _my_val(init_val)
		{
		}

		int value() { return _my_val; }

		void add(int b) { _my_val += b; }

	protected:
		int _my_val{ 0 };
	};
}; // namespace hytano

