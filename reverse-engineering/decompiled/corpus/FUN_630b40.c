/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x630b40; label: FUN_00630b40
 */

void FUN_00630b40(uint *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_029130e4 != (int *)0x0) {
    FUN_0062a5e0();
  }
  DAT_029130e4 = (int *)(*param_1 + 0xf & 0xfffffff0);
  *param_1 = (*param_1 + 0xf & 0xfffffff0) + 0x38;
  _memset(DAT_029130e4,0,0x38);
  *DAT_029130e4 = param_3;
  DAT_029130e4[1] = param_4;
  DAT_029130e4[2] = param_5;
  DAT_029130e4[5] = param_6;
  if (DAT_029130e4[1] != 0) {
    DAT_029130e4[6] = *param_1 + 3 & 0xfffffffc;
    uVar1 = *param_1 + 3 & 0xfffffffc;
    *param_1 = uVar1;
    *param_1 = DAT_029130e4[1] * 0x54 + uVar1;
    _memset((void *)DAT_029130e4[6],0,DAT_029130e4[1] * 0x54);
    iVar4 = 0;
    if (0 < DAT_029130e4[1]) {
      iVar3 = 0;
      do {
        iVar2 = DAT_029130e4[6] + iVar3;
        if (DAT_029130e4[2] != 0) {
          *(uint *)(iVar2 + 8) = *param_1 + 3 & 0xfffffffc;
          uVar1 = *param_1 + 3 & 0xfffffffc;
          *param_1 = uVar1;
          uVar1 = uVar1 + DAT_029130e4[2] * 4;
          *param_1 = uVar1;
          *(uint *)(iVar2 + 0xc) = uVar1;
          uVar1 = *param_1 + 3 & 0xfffffffc;
          *param_1 = uVar1;
          uVar1 = uVar1 + DAT_029130e4[2] * 4;
          *param_1 = uVar1;
          *(uint *)(iVar2 + 0x10) = uVar1;
          uVar1 = *param_1 + 3 & 0xfffffffc;
          *param_1 = uVar1;
          *param_1 = uVar1 + DAT_029130e4[2] * 4;
        }
        FUN_0062d2e0(iVar2);
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x54;
      } while (iVar4 < DAT_029130e4[1]);
    }
  }
  if (*DAT_029130e4 != 0) {
    DAT_029130e4[7] = *param_1 + 3 & 0xfffffffc;
    uVar1 = *param_1 + 3 & 0xfffffffc;
    *param_1 = uVar1;
    *param_1 = uVar1 + *DAT_029130e4 * 2;
    _memset((void *)DAT_029130e4[7],0,*DAT_029130e4 * 2);
  }
  if (DAT_029130e4[5] == 0) {
    DAT_029130e4[8] = param_7;
    DAT_029130e4[0xd] = param_8;
    return;
  }
  DAT_029130e4[9] = *param_1 + 3 & 0xfffffffc;
  uVar1 = *param_1 + 3 & 0xfffffffc;
  *param_1 = uVar1;
  *param_1 = DAT_029130e4[5] * 0x34 + uVar1;
  _memset((void *)DAT_029130e4[9],0,DAT_029130e4[5] * 0x34);
  DAT_029130e4[8] = param_7;
  DAT_029130e4[0xd] = param_8;
  return;
}

