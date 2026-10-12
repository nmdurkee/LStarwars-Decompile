/* Ghidra pseudocode, not original source.
 * ev_63eb9bd68174043ae1497f20c7ab174ab5c86e6d078dec24e1a9d3709ec9fcaa
 * Entry: 0x5fa540; label: FUN_005fa540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fa540(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  FUN_006e54e0(param_1,9,*param_2 & 0xf);
  if (((*param_2 >> 4 ^ *param_2) & 0xf) == 0) {
    uVar1 = 0xc1200000;
  }
  else {
    uVar1 = 0;
  }
  FUN_006e54e0(param_1,8,uVar1);
  FUN_006e54e0(param_1,1,*param_2 >> 8 & 7);
  FUN_006e54e0(param_1,2,*param_2 >> 0xb & 7);
  FUN_006e54e0(param_1,3,*param_2 >> 0xe & 7);
  FUN_006e54e0(param_1,5,*param_2 >> 0x11 & 7);
  FUN_006e54e0(param_1,6,*param_2 >> 0x14 & 7);
  FUN_006e54e0(param_1,7,*param_2 >> 0x17 & 7);
  FUN_006e54e0(param_1,4,param_2[1]);
  (&DAT_0097f9b8)[param_1 * 2] = *param_2;
  (&DAT_0097f9bc)[param_1 * 2] = param_2[1];
  return;
}

