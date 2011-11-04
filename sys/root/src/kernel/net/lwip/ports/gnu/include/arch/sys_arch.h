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

#ifndef __SYS_MSVC_ARCH_H__
#define __SYS_MSVC_ARCH_H__


#include "kernel/core/kernel_pthread.h"
#include "kernel/core/kernel_pthread_mutex.h"
#include "kernel/core/kernel_sem.h"

typedef cyg_handle_t	mbox_hdl;
typedef cyg_mbox		mbox_t;

typedef struct{
   //OS_MAILBOX  os_mailbox;
	mbox_hdl mb_handle;
	mbox_t mbox;
}sys_mbox_st;

typedef sys_mbox_st* sys_mbox_t;

//typedef OS_CSEMA*                sys_sem_t;
typedef cyg_sem_t *					sys_sem_t;
typedef kernel_pthread_t *       sys_thread_t;
typedef kernel_pthread_mutex_t*  sys_prot_t;

#define SYS_MBOX_NULL (sys_mbox_t)NULL
#define SYS_SEM_NULL  (sys_sem_t)NULL

#endif

