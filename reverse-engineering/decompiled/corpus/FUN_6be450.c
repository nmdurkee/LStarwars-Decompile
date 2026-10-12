/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6be450; label: FUN_006be450
 */

void FUN_006be450(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 *in_ECX;
  
  in_ECX[6] = param_4;
  in_ECX[8] = param_3;
  in_ECX[0xc] = param_6;
  in_ECX[10] = param_5;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[1] = *param_1 + 0xf & 0xfffffff0;
  uVar1 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = uVar1;
  *param_1 = uVar1 + in_ECX[6] * 0xc;
  _memset((void *)in_ECX[1],0,in_ECX[6] * 0xc);
  in_ECX[2] = *param_1 + 0xf & 0xfffffff0;
  uVar1 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = uVar1;
  *param_1 = uVar1 + in_ECX[8] * 0x18;
  _memset((void *)in_ECX[2],0,in_ECX[8] * 0x18);
  in_ECX[3] = *param_1 + 0xf & 0xfffffff0;
  uVar1 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = uVar1;
  *param_1 = uVar1 + in_ECX[10] * 8;
  _memset((void *)in_ECX[3],0,in_ECX[10] * 8);
  in_ECX[4] = *param_1 + 0xf & 0xfffffff0;
  uVar1 = *param_1 + 0xf & 0xfffffff0;
  *param_1 = uVar1;
  *param_1 = uVar1 + in_ECX[0xc] * 4;
  _memset((void *)in_ECX[4],0,in_ECX[0xc] * 4);
  *in_ECX = 1;
  return;
}

