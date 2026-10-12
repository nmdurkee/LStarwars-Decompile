/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55b260; label: FUN_0055b260
 */

undefined4 FUN_0055b260(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_2;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (((short)param_2[1] == *(short *)(param_3 + 2)) &&
       (iVar1 = FUN_004f8b10(iVar1,*param_3), iVar1 == 0)) break;
    iVar1 = param_2[2];
    param_2 = param_2 + 2;
  }
  FUN_004f1f10(param_4,param_1);
  FUN_004f1e80(param_4,*param_3);
  param_3[1] = param_3[1] & 0xfffffff7;
  return 1;
}

