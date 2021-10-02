#include<stdio.h>
#include<math.h>
 
#define N 8
 
//�ṹ�嶨��
struct chooseLocale
 
{
 
	double x;
 
	double y;
 
	int w;
 
	double xp;
 
	double yp;
 
} location[N];
 
double  g_minX=0;
double g_maxX=0;
double g_minY=0;
double g_maxY=0;
double g_minSum=30000;
double g_shopX=0;
double g_shopY=0;
int g_iCount=0;
 
 
double get_length(double x,double y,double x1,double y1);
void getEdgelocation();
void inputHouselocation();
void getShoplocation();
 
 
int main()
 
{
 
	inputHouselocation();
	getEdgelocation();
	getShoplocation();
 
	printf("count=%d\n",g_iCount);//��ӡsum�������
	printf("minsum=%lf\n",g_minSum);
	printf("����������꽨���ĵ�������Ϊ��\nlocation(%lf,%lf)\n",g_shopX,g_shopY);
	return 0;
 
}
 
double get_length(double x,double y,double x1,double y1) {
 
 
	return(sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)));
}
/*
  ���������λ����
 (10��20,30) , (30��34,45) , (19��25,28) , (38��49.1,8) , (9,38.1,36) , (2,34,16) , (5,8,78) , (29,48,56)
*/
void inputHouselocation() {
	for(int i=0; i<N; i++) {
		printf("Please input House %d locationInfo :\n",i);
		scanf("%lf%lf%d",&location[i].x,&location[i].y,&location[i].w);
	}
}
/*
  �ҵ��˸���λ������ı�Ե�㣬����С������Χ��
*/
void getEdgelocation() {
 
	for(int i=0; i<N; i++) {
		if(location[i].x<g_minX) {
			g_minX=location[i].x;
		} else {
			g_maxX=location[i].x;
		}
		if(location[i].y<g_minY) {
			g_minY=location[i].y;
		} else {
			g_maxY=location[i].y;
		}
 
	}
}
 
void getShoplocation() {
	struct chooseLocale	cl;
	double len[8]= {0};
	double sum=0;
 
 
	for(cl.xp=g_minX; cl.xp<=g_maxX; cl.xp++)
 
	{
 
		for(cl.yp=g_minY; cl.yp<=g_maxY; cl.yp++)
 
		{
 
 
			for(int i=0; i<N; i++)
 
			{
 
				len[i]=get_length(location[i].x,location[i].y,cl.xp,cl.yp);
 
				len[i]=len[i]*location[i].w;
 
				sum=sum+len[i];
				g_iCount++;
 
			}
 
			if(sum<g_minSum) {
 
				g_minSum=sum;
				g_shopX=cl.xp;
				g_shopY=cl.yp;
 
			}
			sum=0;
 
		}
 
 
	}
}


