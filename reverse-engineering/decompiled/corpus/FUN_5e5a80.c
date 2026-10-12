/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5a80; label: FUN_005e5a80
 */

void FUN_005e5a80(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = param_2 + param_3 * 4;
  iVar2 = (int)puVar5 + (0xf - (int)param_2);
  if (3 < (int)(iVar2 + (iVar2 >> 0x1f & 0xfU)) >> 4) {
    puVar3 = param_1 + 6;
    puVar4 = param_2 + 6;
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 0x10;
      *param_1 = uVar1;
      param_1 = param_1 + 0x10;
      puVar3[-5] = puVar4[-5];
      puVar3[-4] = puVar4[-4];
      puVar3[-3] = puVar4[-3];
      puVar3[-2] = puVar4[-2];
      puVar3[-1] = puVar4[-1];
      *puVar3 = *puVar4;
      puVar3[1] = puVar4[1];
      puVar3[2] = puVar4[2];
      puVar3[3] = puVar4[3];
      puVar3[4] = puVar4[4];
      puVar3[5] = puVar4[5];
      puVar3[6] = puVar4[6];
      puVar3[7] = puVar4[7];
      puVar3[8] = puVar4[8];
      puVar3[9] = puVar4[9];
      puVar3 = puVar3 + 0x10;
      puVar4 = puVar4 + 0x10;
    } while ((int)param_2 < (int)(puVar5 + -0xc));
  }
  for (; param_2 < puVar5; param_2 = param_2 + 4) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1 = param_1 + 4;
  }
  return;
}

