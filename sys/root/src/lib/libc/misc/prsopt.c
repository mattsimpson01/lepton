/*
The contents of this file are subject to the Mozilla Public License Version 1.1 
(the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis, 
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for the 
specific language governing rights and limitations under the License.

The Original Code is ______________________________________.

The Initial Developer of the Original Code is ________________________.
Portions created by ______________________ are Copyright (C) ______ _______________________.
All Rights Reserved.

Contributor(s): ______________________________________.

Alternatively, the contents of this file may be used under the terms of the eCos GPL license 
(the  [eCos GPL] License), in which case the provisions of [eCos GPL] License are applicable 
instead of those above. If you wish to allow use of your version of this file only under the
terms of the [eCos GPL] License and not to allow others to use your version of this file under 
the MPL, indicate your decision by deleting  the provisions above and replace 
them with the notice and other provisions required by the [eCos GPL] License. 
If you do not delete the provisions above, a recipient may use your version of this file under 
either the MPL or the [eCos GPL] License."
*/


/*===========================================
Includes
=============================================*/
#include "string.h"
#include "prsopt.h"

/*===========================================
Global Declaration
=============================================*/


/*===========================================
Implementation
=============================================*/
/*-------------------------------------------
| Name:prsopt
| Description:
| Parameters:
| Return Type:
| Comments:
| See:
---------------------------------------------*/
struct opt_t* prsopt(struct prsopt_t* prsr_opt,char* string,const char* opt){
   char * p = 0;

   //init
   if(string){
      prsr_opt->len = strlen(string);
      prsr_opt->p   = string;
      prsr_opt->i   = 0;
   }

   prsr_opt->opt   = 0;
   prsr_opt->v     = 0;

   p = prsr_opt->p;

   for(prsr_opt->i=0;prsr_opt->len && p;prsr_opt->i++){

      prsr_opt->len--;
      if( (p[prsr_opt->i]=='-')
         && !prsr_opt->opt){
         int o=0;
         int l;
         
         p[prsr_opt->i]=0x00;

         //get option
         prsr_opt->i++;

         l =strlen(opt);
         for(o=0;o<l;o++){
            if(opt[o]==p[prsr_opt->i]) 
               break;
            else if (o+1==l)
               return 0;
         }

         prsr_opt->opt = p[prsr_opt->i];

         prsr_opt->len--;
         p[prsr_opt->i]=0x00;
         p = &p[prsr_opt->i+1];
         prsr_opt->i =0;
         if(!(*p))
            return (struct opt_t*)prsr_opt;
      }else if(prsr_opt->opt 
         && !prsr_opt->v
         && p[prsr_opt->i]!=' '){
         prsr_opt->v = &p[prsr_opt->i];
         //p = &p[prsr_opt->i+1];
      }else if(prsr_opt->opt 
               && prsr_opt->v
               && (p[prsr_opt->i]==' '
               || p[prsr_opt->i]=='\n'
               || p[prsr_opt->i]=='\0')){

         if(p[prsr_opt->i]=='\0')
            prsr_opt->len=0;
         
         p[prsr_opt->i]=0x00;
         prsr_opt->p = &p[prsr_opt->i+1];
         prsr_opt->i =0;
         return (struct opt_t*)prsr_opt;
      }
   }

   return 0;
}


/*===========================================
End of Sourceprsopt.c
=============================================*/
