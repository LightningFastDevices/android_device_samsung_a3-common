/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above
	  copyright notice, this list of conditions and the following
	  disclaimer in the documentation and/or other materials provided
	  with the distribution.
	* Neither the name of The Linux Foundation nor the names of its
	  contributors may be used to endorse or promote products derived
	  from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <init_msm8916.h>

using android::base::GetProperty;

void init_target_properties(void)
{
	std::string bootloader = GetProperty("ro.bootloader","");

	char *bootloader_str = NULL;
	char *build_id = NULL;
	char *device = NULL;
	char *model = NULL;
	char *name = NULL;
	char *operator_alpha = NULL;
	char *operator_numeric = NULL;
	char *version_release = NULL;

    build_id = (char *)"LRX22G";
    version_release = (char *)"5.0.2";

	int network_type = 1;

	if (bootloader.find("A300FU") == 0) {
		device = (char *)"a3ulte";
		model = (char *)"SM-A300FU";
		name = (char *)"a3ultexx";
		network_type=LTE_DEVICE;
	}
	else if (bootloader.find("A300YZ") == 0) {
		device = (char *)"a3ltezt";
		model = (char *)"SM-A300YZ";
		name = (char *)"a3ltezt";
		network_type=LTE_DEVICE;
	}
	else if (bootloader.find("A3000") == 0) {
		device = (char *)"a3ltechn";
		model = (char *)"SM-A3000";
		name = (char *)"a3ltezc";
		network_type=LTE_DEVICE;
	}
	else if (bootloader.find("A3009") == 0) {
		device = (char *)"a3ltectc";
		model = (char *)"SM-A3009";
		name = (char *)"a3ltectc";
		network_type=LTE_DEVICE;
	}
	else if (bootloader.find("A300F") == 0) {
		device = (char *)"a3lte";
		model = (char *)"SM-A300F";
		name = (char *)"a3ltexx";
		network_type=LTE_DEVICE;
	}
	else if (bootloader.find("A300H") == 0) {
		device = (char *)"a33g";
		model = (char *)"SM-A300H";
		name = (char *)"a33g";
		network_type=GSM_DEVICE;
	}
	else if (bootloader.find("A300M") == 0) {
		device = (char *)"a3lte";
		model = (char *)"SM-A300M";
		name = (char *)"a3lteub";
		network_type=LTE_DEVICE;
	}
	else if (bootloader.find("A300G") == 0) {
		device = (char *)"a3ltedd";
		model = (char *)"SM-A300G";
		name = (char *)"a3ltezso";
		network_type=LTE_DEVICE;
	}
	else if (bootloader.find("A300Y") == 0) {
		device = (char *)"a3ulte";
		model = (char *)"SM-A300Y";
		name = (char *)"a3ultedv";
		network_type=LTE_DEVICE;
	}
	else {
		return;
	}

	/* make sure device name is set */
	if (name == NULL)
		name = device;

	/* set the properties */
	set_target_properties(build_id, bootloader_str, name, device, model,
		       network_type, operator_alpha, operator_numeric, version_release);
}
