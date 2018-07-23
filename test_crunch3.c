#include<stdio.h>
#include <iostream>
#include<stdlib.h>
#include <string.h>
#include <strings.h>
#include <list>
#include <algorithm>
#include <gsl/gsl_sf_bessel.h>
#include <gsl/gsl_fit.h>
#include <math.h>
#include <map>

using namespace std;

int main(int argc, char **argv) {

  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("test4.csv", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  int line_count=0;

  while ((read = getline(&line, &len, fp)) != -1) {
    line_count+=1;
  }

  printf("line_count: %d\n",line_count);

  fclose(fp);


  char date_stamp[120];
  int ucid=0;
  int close_year=0;
  int recv_year=0;
  char borough[120];
  char investigation_on[10];
  char complain_video[10];
  char complain_filed_mode[100];
  char complain_filed_place[120];
  char frisk_alleg[10];
  char location[120];
  char incident_year[20];
  char outcome[120];
  char reason_contact[150];
  char fado_type[120];
  char alleg_desc[140];


  fp=fopen("test4.csv", "r");
  
  int i=0;

  std::list<int> list_complaints;

  int unique_complaints=0;
  int unqiue_complaints_manhattan=0;
  int unqiue_complaints_bronx=0;
  int unqiue_complaints_queens=0;
  int unqiue_complaints_staten=0;
  int unqiue_complaints_brooklyn=0;
  int unqiue_complaints_outside=0;
  int unqiue_complaints_na=0;

  bool is_complain_in_list=false;

  int years_counter=0;
  int years_total=0;

  int complaints_recv_2016_manhattan=0;
  int complaints_recv_2016_bronx=0;
  int complaints_recv_2016_queens=0;
  int complaints_recv_2016_staten=0;
  int complaints_recv_2016_brooklyn=0;
    
  int stop_and_frisk[19]; // 0 => 1999, 1=> 2000... 18=> 2017

  for(i=0;i<19;i++) {
    stop_and_frisk[i]=0;
  }

  int full_investigation_yes=0;
  int full_investigation_no=0;
  int video_investigation_yes=0;
  int video_investigation_no=0;



  for(i=0;i<line_count;i++) {

  fscanf(fp,
  "%[^,],%d,%d,%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
		       date_stamp,&ucid,&close_year,
		       &recv_year,borough,investigation_on,
		       complain_video,complain_filed_mode,complain_filed_place,frisk_alleg,
		       location,incident_year,outcome,
		       reason_contact,fado_type,alleg_desc);


  is_complain_in_list = (std::find(list_complaints.begin(), list_complaints.end(), ucid) != list_complaints.end());

  if(!is_complain_in_list) {

    list_complaints.push_back(ucid);

    unique_complaints+=1;

    if(strncmp(borough,"Manhattan",9)==0) {
      unqiue_complaints_manhattan+=1;

      years_total=years_total+(close_year-recv_year);
      years_counter++;

      if(recv_year==2016) {
	complaints_recv_2016_manhattan+=1;
      }

      if(strncmp(investigation_on,"TRUE",4)==0) {
	full_investigation_yes++;
      }
      if(strncmp(investigation_on,"FALSE",5)==0) {
	full_investigation_no++;
      }
      if(strncmp(complain_video,"TRUE",4)==0) {
	video_investigation_yes++;
      }
      if(strncmp(complain_video,"FALSE",5)==0) {
	video_investigation_no++;
      }
	
    }
    if(strncmp(borough,"Bronx",5)==0) {
      unqiue_complaints_bronx+=1;
      years_total=years_total+(close_year-recv_year);
      years_counter++;

      if(recv_year==2016) {
	complaints_recv_2016_bronx+=1;
      }

      if(strncmp(investigation_on,"TRUE",4)==0) {
	full_investigation_yes++;
      }
      if(strncmp(investigation_on,"FALSE",5)==0) {
	full_investigation_no++;
      }
      if(strncmp(complain_video,"TRUE",4)==0) {
	video_investigation_yes++;
      }
      if(strncmp(complain_video,"FALSE",5)==0) {
	video_investigation_no++;
      }



    }
    if(strncmp(borough,"Queens",6)==0) {
      unqiue_complaints_queens+=1;

      years_total=years_total+(close_year-recv_year);
      years_counter++;

      if(recv_year==2016) {
	complaints_recv_2016_queens+=1;
      }


      if(strncmp(investigation_on,"TRUE",4)==0) {
	full_investigation_yes++;
      }
      if(strncmp(investigation_on,"FALSE",5)==0) {
	full_investigation_no++;
      }
      if(strncmp(complain_video,"TRUE",4)==0) {
	video_investigation_yes++;
      }
      if(strncmp(complain_video,"FALSE",5)==0) {
	video_investigation_no++;
      }


    }

    if(strncmp(borough,"Staten Island",13)==0) {
      unqiue_complaints_staten+=1;


      years_total=years_total+(close_year-recv_year);
      years_counter++;

      if(recv_year==2016) {
	complaints_recv_2016_staten+=1;
      }


      if(strncmp(investigation_on,"TRUE",4)==0) {
	full_investigation_yes++;
      }
      if(strncmp(investigation_on,"FALSE",5)==0) {
	full_investigation_no++;
      }
      if(strncmp(complain_video,"TRUE",4)==0) {
	video_investigation_yes++;
      }
      if(strncmp(complain_video,"FALSE",5)==0) {
	video_investigation_no++;
      }

    }

    if(strncmp(borough,"Brooklyn",8)==0) {
      unqiue_complaints_brooklyn+=1;
  
      years_total=years_total+(close_year-recv_year);
      years_counter++;

      if(recv_year==2016) {
	complaints_recv_2016_brooklyn+=1;
      }


      if(strncmp(investigation_on,"TRUE",4)==0) {
	full_investigation_yes++;
      }
      if(strncmp(investigation_on,"FALSE",5)==0) {
	full_investigation_no++;
      }
      if(strncmp(complain_video,"TRUE",4)==0) {
	video_investigation_yes++;
      }
      if(strncmp(complain_video,"FALSE",5)==0) {
	video_investigation_no++;
      }


    }
    if(strncmp(borough,"Outside NYC",11)==0) {
      unqiue_complaints_outside+=1;

    }

    if(strncmp(borough,"NA",11)==0) {
      unqiue_complaints_na+=1;

    }


    if(strncmp(borough,"Manhattan",9)==0) {
      unqiue_complaints_manhattan+=1;

      years_total=years_total+(close_year-recv_year);
      years_counter++;

      if(recv_year==2016) {
	complaints_recv_2016_manhattan+=1;
      }


    }

    // stop and frisk
  
    if(strncmp(frisk_alleg,"TRUE",4)==0) {
      stop_and_frisk[recv_year-1999]+=1;
    }


  }


  is_complain_in_list=true;



  bzero(date_stamp,120);
  ucid=0;
  close_year=0;
  recv_year=0;
  bzero(borough,120);
  bzero(investigation_on,10);
  bzero(complain_video,10);
  bzero(complain_filed_mode,100);
  bzero(complain_filed_place,120);
  bzero(frisk_alleg,10);
  bzero(location,120);
  bzero(incident_year,20);
  bzero(outcome,120);
  bzero(reason_contact,150);
  bzero(fado_type,120);
  bzero(alleg_desc,140);


}

  list_complaints.sort();
  list_complaints.unique();
  int list_unique_complaints=list_complaints.size();
  std::cout <<"Unique complaints: "<<list_unique_complaints << std::endl;

  std::cout<<"unqiue_complaints_manhattan: "<<unqiue_complaints_manhattan<<std::endl;
  std::cout<<"unqiue_complaints_bronx: "<<unqiue_complaints_bronx<<std::endl;
  std::cout<<"unqiue_complaints_queens: "<<unqiue_complaints_queens<<std::endl;
  std::cout<<"unqiue_complaints_staten: "<<unqiue_complaints_staten<<std::endl;
  std::cout<<"unqiue_complaints_brooklyn: "<<unqiue_complaints_brooklyn<<std::endl;
  std::cout<<"unqiue_complaints_outside: "<<unqiue_complaints_outside<<std::endl;
  std::cout<<"unqiue_complaints_na: "<<unqiue_complaints_na<<std::endl;

  // From the first run of the code Apriori we know Brooklyn has the most complaints
  // a more general version can also be written, but due to the lack of time,
  // the apriori assumption is taken

  double brooklyn_complaints_proportion=0.0;
  int total_uniq_complaints=0;

  total_uniq_complaints=unqiue_complaints_manhattan+unqiue_complaints_bronx+unqiue_complaints_queens+unqiue_complaints_staten+unqiue_complaints_brooklyn;

  printf("total_uniq_complaints: %d\n",total_uniq_complaints);

  brooklyn_complaints_proportion=(double)unqiue_complaints_brooklyn/(double)total_uniq_complaints;
  printf("Total Brooklyn proportion: %10.15lf\n",brooklyn_complaints_proportion);

  printf("years_total: %d\n",years_total);
  printf("years_counter: %d\n",years_counter);

  double avg_years_complain_closed=0.0;
  avg_years_complain_closed=(double)years_total/(double)years_counter;
  printf("avg_years_complain_closed: %10.15lf\n",avg_years_complain_closed);

  // 2016 borough population estimates from: 
  // https://projects.amny.com/long-island/nyc-population-estimates/

  int population_manhattan_2016=1662164;
  int population_bronx_2016=1468976;
  int population_staten_2016=477383;
  int population_brooklyn_2016=2650859;
  int population_queens_2016=2356044;

  printf("complaints_recv_2016_manhattan: %d\n",complaints_recv_2016_manhattan);
  printf("complaints_recv_2016_bronx: %d\n",complaints_recv_2016_bronx);
  printf("complaints_recv_2016_staten: %d\n",complaints_recv_2016_staten);
  printf("complaints_recv_2016_brooklyn: %d\n",complaints_recv_2016_brooklyn);
  printf("complaints_recv_2016_queens: %d\n",complaints_recv_2016_queens);
  
  printf("Manhattan complaints per 100k: %10.15lf\n",(double)complaints_recv_2016_manhattan/((double)population_manhattan_2016/(double)100000.0));


  printf("Bronx complaints per 100k: %10.15lf\n",(double)complaints_recv_2016_bronx/((double)population_bronx_2016/(double)100000.0));


  printf("Staten Island complaints per 100k: %10.15lf\n",(double)complaints_recv_2016_staten/((double)population_staten_2016/(double)100000.0));

  printf("Brooklyn complaints per 100k: %10.15lf\n",(double)complaints_recv_2016_brooklyn/((double)population_brooklyn_2016/(double)100000.0));

  printf("Queens complaints per 100k: %10.15lf\n",(double)complaints_recv_2016_queens/((double)population_queens_2016/(double)100000.0));

  // Stop and Frisk

  // Max Stop and Frisk year was Year: 2007 Incidents S&F: 2557

  double reg_years[12];
  double reg_sf[12];

  int n=0;

  for(i=0;i<19;i++) {
    if(i>=8) {
      n++;
      reg_sf[i-8]=stop_and_frisk[i];
      reg_years[i-8]=1999+i;
    }
  }


  double c0, c1, cov00, cov01, cov11, sumsq;

  gsl_fit_linear (reg_years, 1, reg_sf, 1, n, &c0, &c1, &cov00, &cov01, &cov11, &sumsq);

  printf("Y = c0 + c1*X \n");

  printf("c0:%lf c1:%lf cov00:%lf cov01:%lf cov11:%lf sumsq:%lf\n",c0,c1,cov00,cov01,cov11,sumsq);

  double Y=c0+(c1*2018.0);

  printf("For year 2018, i.e. X=2018, number of stop & frisk incidents i.e. Y=%10.15lf\n",Y);

  printf("Rounded: %d\n",(int)Y);


  printf("full_investigation_yes: %d\n",full_investigation_yes);
  printf("full_investigation_no: %d\n",full_investigation_no);
  printf("video_investigation_yes: %d\n",video_investigation_yes);
  printf("video_investigation_no: %d\n",video_investigation_no);

  int total_full_investigation=full_investigation_yes+full_investigation_no;
  int total_video_investigation=video_investigation_yes+video_investigation_no;
  int total_yes=full_investigation_yes+video_investigation_yes;
  int total_no=full_investigation_no+video_investigation_no;
  int total_total=total_full_investigation+total_video_investigation;

  double exp_full_investigation_yes=0.0;
  double exp_full_investigation_no=0.0;
  double exp_video_investigation_yes=0.0;
  double exp_video_investigation_no=0.0;

  exp_full_investigation_yes=((double)total_full_investigation*(double)total_yes)/(double)total_total;

  exp_full_investigation_no=((double)total_full_investigation*(double)total_no)/(double)total_total;

  exp_video_investigation_yes=((double)total_video_investigation*(double)total_yes)/(double)total_total;

  exp_video_investigation_no=((double)total_video_investigation*(double)total_no)/(double)total_total;

  printf("exp_full_investigation_yes: %10.10lf\n",exp_full_investigation_yes);
  printf("exp_full_investigation_no: %10.10lf\n",exp_full_investigation_no);
  printf("exp_video_investigation_yes: %10.10lf\n",exp_video_investigation_yes);
  printf("exp_video_investigation_no: %10.10lf\n",exp_video_investigation_no);

  double chi1=0.0,chi2=0.0,chi3=0.0,chi4=0.0;

  chi1=pow((full_investigation_yes-exp_full_investigation_yes),2)/exp_full_investigation_yes;
  chi2=pow((full_investigation_no-exp_full_investigation_no),2)/exp_full_investigation_no;
  chi3=pow((video_investigation_yes-exp_video_investigation_yes),2)/exp_video_investigation_yes;
  chi4=pow((video_investigation_no-exp_video_investigation_no),2)/exp_video_investigation_no;

  printf("chi1: %10.15lf\n",chi1);
  printf("chi2: %10.15lf\n",chi2);
  printf("chi3: %10.15lf\n",chi3);
  printf("chi4: %10.15lf\n",chi4);
    
  double chi_sq=chi1+chi2+chi3+chi4;

  printf("chi_sq: %10.15lf\n",chi_sq);



  printf("population_manhattan_2016: %d\n",population_manhattan_2016);
  printf("complaints_recv_2016_manhattan: %d\n",complaints_recv_2016_manhattan);
  double complaints_per_capita_manhattan=0.0;
  complaints_per_capita_manhattan=(double)complaints_recv_2016_manhattan/(double)population_manhattan_2016;
  printf("complaints_per_capita_manhattan: %10.15lf\n",complaints_per_capita_manhattan);
  int num_precinct_manhattan=22;
  double num_officers_per_capita_manhattan=(double)complaints_per_capita_manhattan*(double)num_precinct_manhattan;
  printf("num_officers_per_capita_manhattan: %10.15lf\n",num_officers_per_capita_manhattan);

  printf("population_bronx_2016: %d\n",population_bronx_2016);
  printf("complaints_recv_2016_bronx: %d\n",complaints_recv_2016_bronx);
  double complaints_per_capita_bronx=0.0;
  complaints_per_capita_bronx=(double)complaints_recv_2016_bronx/(double)population_bronx_2016;
  printf("complaints_per_capita_bronx: %10.15lf\n",complaints_per_capita_bronx);
  int num_precinct_bronx=12;
  double num_officers_per_capita_bronx=(double)complaints_per_capita_bronx*(double)num_precinct_bronx;
  printf("num_officers_per_capita_bronx: %10.15lf\n",num_officers_per_capita_bronx);



  printf("population_staten_2016: %d\n",population_staten_2016);
  printf("complaints_recv_2016_staten: %d\n",complaints_recv_2016_staten);
  double complaints_per_capita_staten=0.0;
  complaints_per_capita_staten=(double)complaints_recv_2016_staten/(double)population_staten_2016;
  printf("complaints_per_capita_staten: %10.15lf\n",complaints_per_capita_staten);
  int num_precinct_staten=4;
  double num_officers_per_capita_staten=(double)complaints_per_capita_staten*(double)num_precinct_staten;
  printf("num_officers_per_capita_staten: %10.15lf\n",num_officers_per_capita_staten);


  printf("population_brooklyn_2016: %d\n",population_brooklyn_2016);
  printf("complaints_recv_2016_brooklyn: %d\n",complaints_recv_2016_brooklyn);
  double complaints_per_capita_brooklyn=0.0;
  complaints_per_capita_brooklyn=(double)complaints_recv_2016_brooklyn/(double)population_brooklyn_2016;
  printf("complaints_per_capita_brooklyn: %10.15lf\n",complaints_per_capita_brooklyn);
  int num_precinct_brooklyn=23;
  double num_officers_per_capita_brooklyn=(double)complaints_per_capita_brooklyn*(double)num_precinct_brooklyn;
  printf("num_officers_per_capita_brooklyn: %10.15lf\n",num_officers_per_capita_brooklyn);



  printf("population_queens_2016: %d\n",population_queens_2016);
  printf("complaints_recv_2016_queens: %d\n",complaints_recv_2016_queens);
  double complaints_per_capita_queens=0.0;
  complaints_per_capita_queens=(double)complaints_recv_2016_queens/(double)population_queens_2016;
  printf("complaints_per_capita_queens: %10.15lf\n",complaints_per_capita_queens);
  int num_precinct_queens=16;
  double num_officers_per_capita_queens=(double)complaints_per_capita_queens*(double)num_precinct_queens;
  printf("num_officers_per_capita_queens: %10.15lf\n",num_officers_per_capita_queens);

  // multirun Apriori observation
  // max is num_officers_per_capita_manhattan
  // min is num_officers_per_capita_staten

  printf("\nratio of max number of officers to min number of officers: %10.15lf\n",(double)num_officers_per_capita_manhattan/(double)num_officers_per_capita_staten);




  fclose(fp);
  if (line)
  free(line);
  exit(EXIT_SUCCESS);


  return 0;
}
