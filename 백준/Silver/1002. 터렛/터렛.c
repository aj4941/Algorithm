#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, r1, x2, y2, r2;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		double d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);/*원 좌표 사이의 거리*/

		if (d == 0) {/*원의 좌표가 같을 때*/
			if (r1 == r2) {
				printf("-1");
			}
			else {
				printf("0");
			}
		}
		else {	/*원의 좌표가 다를 때*/
			if (d < (r2 - r1)*(r2 - r1)) {/*안에 있는경우*/
				printf("0");
			}
			else if (d == (r2 - r1)*(r2 - r1)) {/*내접*/
				printf("1");
			}

			else if(d>(r2-r1)*(r2-r1)&&d<(r1+r2)*(r1+r2)){/*교점이 2개*/
					printf("2");
			}
			else if (d == (r1 + r2)*(r1 + r2)) {/*외접*/
					printf("1");
			}
			else if(d>(r1+r2)*(r1+r2)) {/*만나지 않는 경우*/
					printf("0");
				}
			}
        printf("\n");
		}/*<- for문 괄호*/
	return 0;
}