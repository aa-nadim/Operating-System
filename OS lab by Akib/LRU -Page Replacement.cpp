#include<stdio.h>


int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);

	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);

	printf("Enter reference string: ");

    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &pages[i]);
    }

	for(i = 0; i < no_of_frames; ++i){
    	frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i){
    	flag1 = flag2 = 0;

    	for(j = 0; j < no_of_frames; ++j){
    		if(frames[j] == pages[i]){
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}

    	if(flag1 == 0){
			for(j = 0; j < no_of_frames; ++j){
	    		if(frames[j] == -1){
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			break;
	    		}
    		}
    	}

    	if(flag2 == 0){

            int  minimum = 1e9;
            pos=0;
            for(j = 0; j < no_of_frames; ++j){
                if(time[j] < minimum){
                    minimum = time[j];
                    pos = j;
                }
            }
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}

    	printf("\n");

    	for(j = 0; j < no_of_frames; ++j){
    		printf("%d\t", frames[j]);
    	}
	}
	printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
