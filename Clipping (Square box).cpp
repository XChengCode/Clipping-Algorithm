void clip_polygon()
{
	//top clip
	std::vector<Point> tempPoints;
	for (int eindex = 0; eindex < needclipPoints.size(); eindex++)
	{
		Point startPoint = needclipPoints[eindex];
		Point endPoint = (eindex == (needclipPoints.size() - 1)) ? needclipPoints[0] : needclipPoints[eindex + 1];

		unsignedint rc_ps = enCode(startPoint.x, startPoint.y);
		unsignedint rc_pe = enCode(endPoint.x, endPoint.y);

		if ((rc_ps &8) == 0&& (rc_pe &8) == 0)//均在内侧
		{
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &8) && (rc_pe &8) == 0)//起始点在外，终点在内
		{
			float k = (endPoint.x - startPoint.x) / (endPoint.y - startPoint.y);
			Point new_intersect_point;
			new_intersect_point.y = clip_win_y_max;
			new_intersect_point.x = (clip_win_y_max - startPoint.y) * k + startPoint.x;
			tempPoints.push_back(new_intersect_point);
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &8) == 0&& (rc_pe &8))//起始点在内，终点在外
		{
			float k = (endPoint.x - startPoint.x) / (endPoint.y - startPoint.y);
			Point new_intersect_point;
			new_intersect_point.y = clip_win_y_max;
			new_intersect_point.x = (clip_win_y_max - endPoint.y) * k + endPoint.x;
			tempPoints.push_back(new_intersect_point);
		}
	}
	needclipPoints.clear();
	needclipPoints.assign(tempPoints.begin(), tempPoints.end());
	tempPoints.clear();

	for (int eindex = 0; eindex < needclipPoints.size(); eindex++)
	{
		Point startPoint = needclipPoints[eindex];
		Point endPoint = (eindex == (needclipPoints.size() - 1)) ? needclipPoints[0] : needclipPoints[eindex + 1];

		unsignedint rc_ps = enCode(startPoint.x, startPoint.y);
		unsignedint rc_pe = enCode(endPoint.x, endPoint.y);

		if ((rc_ps &4) == 0&& (rc_pe &4) == 0)//均在内侧
		{
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &4) && (rc_pe &4) == 0)//起始点在外，终点在内
		{
			float k = (endPoint.x - startPoint.x) / (endPoint.y - startPoint.y);
			Point new_intersect_point;
			new_intersect_point.y = clip_win_y_min;
			new_intersect_point.x = (clip_win_y_min - startPoint.y) * k + startPoint.x;
			tempPoints.push_back(new_intersect_point);
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &4) == 0&& (rc_pe &4))//起始点在内，终点在外
		{
			float k = (endPoint.x - startPoint.x) / (endPoint.y - startPoint.y);
			Point new_intersect_point;
			new_intersect_point.y = clip_win_y_min;
			new_intersect_point.x = (clip_win_y_min - endPoint.y) * k + endPoint.x;
			tempPoints.push_back(new_intersect_point);
		}
	}
	needclipPoints.clear();
	needclipPoints.assign(tempPoints.begin(), tempPoints.end());
	tempPoints.clear();

	for (int eindex = 0; eindex < needclipPoints.size(); eindex++)
	{
		Point startPoint = needclipPoints[eindex];
		Point endPoint = (eindex == (needclipPoints.size() - 1)) ? needclipPoints[0] : needclipPoints[eindex + 1];

		unsignedint rc_ps = enCode(startPoint.x, startPoint.y);
		unsignedint rc_pe = enCode(endPoint.x, endPoint.y);

		if ((rc_ps &2) == 0&& (rc_pe &2) == 0)//均在内侧
		{
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &2) && (rc_pe &2) == 0)//起始点在外，终点在内
		{
			float k = (endPoint.y - startPoint.y) / (endPoint.x - startPoint.x);
			Point new_intersect_point;
			new_intersect_point.x = clip_win_x_max;
			new_intersect_point.y = (clip_win_x_max - startPoint.x) * k + startPoint.y;
			tempPoints.push_back(new_intersect_point);
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &2) == 0&& (rc_pe &2))//起始点在内，终点在外
		{
			float k = (endPoint.y - startPoint.y) / (endPoint.x - startPoint.x);
			Point new_intersect_point;
			new_intersect_point.x = clip_win_x_max;
			new_intersect_point.y = (clip_win_x_max - endPoint.x) * k + endPoint.y;
			tempPoints.push_back(new_intersect_point);
		}
	}
	needclipPoints.clear();
	needclipPoints.assign(tempPoints.begin(), tempPoints.end());
	tempPoints.clear();

	for (int eindex = 0; eindex < needclipPoints.size(); eindex++)
	{
		Point startPoint = needclipPoints[eindex];
		Point endPoint = (eindex == (needclipPoints.size() - 1)) ? needclipPoints[0] : needclipPoints[eindex + 1];

		unsignedint rc_ps = enCode(startPoint.x, startPoint.y);
		unsignedint rc_pe = enCode(endPoint.x, endPoint.y);

		if ((rc_ps &1) == 0&& (rc_pe &1) == 0)//均在内侧
		{
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &1) && (rc_pe &1) == 0)//起始点在外，终点在内
		{
			float k = (endPoint.y - startPoint.y) / (endPoint.x - startPoint.x);
			Point new_intersect_point;
			new_intersect_point.x = clip_win_x_min;
			new_intersect_point.y = (clip_win_x_min - startPoint.x) * k + startPoint.y;
			tempPoints.push_back(new_intersect_point);
			tempPoints.push_back(endPoint);
		}
		elseif ((rc_ps &1) == 0&& (rc_pe &1))//起始点在内，终点在外
		{
			float k = (endPoint.y - startPoint.y) / (endPoint.x - startPoint.x);
			Point new_intersect_point;
			new_intersect_point.x = clip_win_x_min;
			new_intersect_point.y = (clip_win_x_min - endPoint.x) * k + endPoint.y;
			tempPoints.push_back(new_intersect_point);
		}
	}
	needclipPoints.clear();
	needclipPoints.assign(tempPoints.begin(), tempPoints.end());
	tempPoints.clear();
}

void move(int xt,int yt)
{
	for (int index = 0; index < gPoints.size(); index++)
	{
		gPoints[index].x = gPoints[index].x + xt;
		gPoints[index].y = gPoints[index].y + yt;
		
	}
	    clip_win_y_max = clip_win_y_max+yt;
		clip_win_y_min = clip_win_y_min+yt;
		clip_win_x_max = clip_win_x_max+xt;
		clip_win_x_min = clip_win_x_min+xt;
}
