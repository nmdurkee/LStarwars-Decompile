/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6a10; label: FUN_006d6a10
 */

void FUN_006d6a10(int param_1)

{
  uint uVar1;
  
  (&DAT_029757f8)[param_1] = 1;
  uVar1 = 0;
  if ((DAT_02975822 != '\0') || (DAT_0297582e != '\0')) {
    uVar1 = 1;
  }
  if ((DAT_02975815 != '\0') || (DAT_02975895 != '\0')) {
    uVar1 = uVar1 | 2;
  }
  if (DAT_029758b0 != '\0') {
    uVar1 = uVar1 | 4;
  }
  switch(param_1) {
  case 0x1d:
  case 0x2a:
  case 0x36:
  case 0x38:
  case 0x9d:
  case 0xb8:
    break;
  default:
    FUN_006d69b0(param_1,uVar1);
  }
  return;
}

