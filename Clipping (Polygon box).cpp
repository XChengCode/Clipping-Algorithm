void clip()
{
	int i;
	int pos1, pos2;
	std::vector<Point> q;
	std::queue<Point> s;

	for (i = 0; i < needclipPoints.size(); ++i)
	{
		if (needclipPoints[i].flag == 1) s.push(needclipPoints[i]);
	}
	
	while (!s.empty())
	{
		Point startPoint = s.front();
		s.pop();
		pos1 = findpos_needclipPoints(startPoint);

		if (needclipPoints[pos1].flag != 1) continue;
		else
		{
			needclipPoints[pos1].flag = 0;
			while (needclipPoints[pos1].flag != -1 && pos1 < needclipPoints.size())
			{
				if (needclipPoints[pos1].flag == 1) needclipPoints[pos1].flag = 0;
				q.push_back(needclipPoints[pos1++]);
				if (pos1 >= needclipPoints.size())
				{
					pos1 %= needclipPoints.size();
				}
			}

			pos2 = findpos_gPoints(needclipPoints[pos1]);
			while (gPoints[pos2].flag != 1 && pos2 < gPoints.size())
			{
				q.push_back(gPoints[pos2++]);
				if (pos2 >= gPoints.size())
				{
					pos2 %= gPoints.size();
				}
			}
		}
	}

	needclipPoints.clear();
	needclipPoints.assign(q.begin(), q.end());
	gPoints.clear();
	gPoints.assign(tgPoints.begin(), tgPoints.end());
}
void generate_cross_points()
{
	int i, j, posinsert;
	bool have_cross;
	int posn, posc;
	int cnt = 0;
	std::vector<Point> t1Points;
	std::vector<Point> t2Points;

	t1Points.assign(needclipPoints.begin(), needclipPoints.end());
	t2Points.assign(gPoints.begin(), gPoints.end());

	for (i = 0; i < needclipEdges.size(); ++i)
	{
		for (int j = 0; j < gEdges.size(); ++j)
		{
			have_cross = HaveCross(needclipEdges[i], gEdges[j]);
			if (have_cross)
			{
				Point p = FigurePoint(needclipEdges[i], gEdges[j]);
				if (is_inside(needclipEdges[i].p1) == true&& is_inside(needclipEdges[i].p2) == false) p.flag = -1;
				else p.flag = 1;
				crossPoints.push_back(p);

				posn = find_needclip(p);
				posc = find_clip(p);

				t1Points.insert(t1Points.begin() + posn + cnt, p);
				t2Points.insert(t2Points.begin() + posc + cnt, p);

				++cnt;
			}
		}
	}
	needclipPoints.clear();
	gPoints.clear();

	needclipPoints.assign(t1Points.begin(), t1Points.end());
	gPoints.assign(t2Points.begin(), t2Points.end());
}
Point FigurePoint(Edgee1, Edgee2)
{
	Point p;
	double k1, k2;
	double b1, b2;
	double  shang, xia;

	k1 = (e1.p1.y - e1.p2.y) / (e1.p1.x - e1.p2.x);
	k2 = (e2.p1.y - e2.p2.y) / (e2.p1.x - e2.p2.x);
	b1 = e1.p1.y - k1 * e1.p1.x;
	b2 = e2.p1.y - k2 * e2.p1.x;

	xia = -k1 + k2;
	shang = b1 - b2;
	p.x = shang / xia;

	shang = -k1 * b2 + k2 * b1;
	p.y = shang / xia;

	return p;
