/* C Program by Manar Abouhenidi for CS1313 April 07 2017.

The Network Program.


Source of light
´´´´´´´´´¶¶*..**..*
´´´´´´´´´¶¶¶ .*.*.*.
¶¶¶´´´´´¶¶´¶*..**.*.
´¶¶¶¶¶¶¶¶´´¶*.*.**..**.
´´´¶¶´´´´´´¶¶¶¶¶¶¶¶¶*.*.*.*.*.
´´´´´¶¶´¶¶´´´´¶¶¶¶*.*.**.
´´´´¶¶´´´´´¶¶¶.**.**.
´´´¶¶´¶¶¶¶´´¶*.*.*.**.
´´¶¶¶¶¶´´¶¶´¶´´´´´´´´¶*.**.*.*.*
´¶¶´´´´´´´´¶¶¶´´´´´´¶¶*..**.*.

 */
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>


 				      /* have a pointer type for */
struct mechpencil { char name[50];          /*   each connection type */
               struct mechpencil *part[6];  /* use an array, OR */
               struct mechpencil *contains1;/* list max. number links */
               struct mechpencil *contains2;
              };
struct mechpencil *mechanicalpencil,*Case, *lead, *end_cup, *coll_spring, *pocket_clip, *push_bottom;
int i,j;


/* creat network for mechanicalpencil */

void create_mechanicalpencil (void)
{

/* get space for the parts */
mechanicalpencil= (struct mechpencil *)malloc(sizeof(struct mechpencil));
Case = (struct mechpencil *)malloc(sizeof(struct mechpencil));
lead = (struct mechpencil *)malloc(sizeof(struct mechpencil));
end_cup= (struct mechpencil *)malloc(sizeof(struct mechpencil));
coll_spring= (struct mechpencil *)malloc(sizeof(struct mechpencil));
pocket_clip= (struct mechpencil *)malloc(sizeof(struct mechpencil));
push_bottom= (struct mechpencil *)malloc(sizeof(struct mechpencil));

/* put parts into name */

strcpy(mechanicalpencil->name, "Mechanical pencil");
strcpy(Case->name, "Case");
strcpy(lead->name, "Lead");
strcpy(end_cup->name, "End_cup");
strcpy(coll_spring->name, "Coll_spring");
strcpy(pocket_clip->name, "Pocket_clip");
strcpy(push_bottom->name, "Push_bottom");

/* connect parts */
mechanicalpencil ->part[0] = Case;
mechanicalpencil ->part[1] = lead;
mechanicalpencil ->part[2] = end_cup;
mechanicalpencil ->part[3] = coll_spring;
mechanicalpencil ->part[4] = pocket_clip;
mechanicalpencil ->part[5] = push_bottom;

/* connect contain */
 Case->contains1 = lead;
 Case->contains2 = coll_spring;

 /* rest of the contains are null */
 mechanicalpencil ->contains1 = NULL;
 mechanicalpencil ->contains2 = NULL;

 Case->contains1 = NULL;
 Case->contains2 = NULL;
 Case->part[0] = NULL;

 lead->contains1 = NULL;
 lead->contains2 = NULL;
 lead->part[0] = NULL;

 end_cup->contains1 = NULL;
 end_cup->contains2 = NULL;
 end_cup->part[0] = NULL;

 coll_spring->contains1 = NULL;
 coll_spring->contains2 = NULL;
 coll_spring->part[0] = NULL;

 pocket_clip->contains1 = NULL;
 pocket_clip->contains2 = NULL;
 pocket_clip->part[0] = NULL;

 push_bottom->contains1 = NULL;
 push_bottom->contains2 = NULL;
 push_bottom->part[0] = NULL;


}

void print_mechanicalpencil (struct mechpencil *thing)
{
int i = 0;

 printf("%s\n", thing->name);

 while (i<6 && thing->part[i] != NULL)  /* print part names */
    {
    	if (thing->contains1!= NULL)
    printf("   Contains:  %s\n", thing->contains1->name);
    else
    printf("   Part:  %s\n", thing->part[i]->name);
    i++;
   }
}



 void main (void)
{
 printf("This program prints out a Mechanical Pencil modeling network;n\n");

 /* create the mechanicalpencil network */
 create_mechanicalpencil ();
 /* print mechanicalpencil network */
 printf("The device Mechanical Pencil looks like: \n\n\n");
 print_mechanicalpencil (mechanicalpencil);
 print_mechanicalpencil (Case);
 print_mechanicalpencil (lead);
 print_mechanicalpencil (coll_spring);
 print_mechanicalpencil (pocket_clip);
 print_mechanicalpencil (push_bottom);
}
