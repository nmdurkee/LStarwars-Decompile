/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52bec0; label: FUN_0052bec0
 */

void FUN_0052bec0(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar2 = FUN_004f7fb0(param_1);
  puVar1 = DAT_00922218;
  if (iVar2 != 0) {
    if (((DAT_00922214 == (int *)0x0) || (DAT_00922218 == (uint *)0x0)) ||
       (*DAT_00922218 <= *DAT_00922214 + 0x14U)) {
      FUN_00512850();
      return;
    }
    uVar3 = *DAT_00922214 + 0xf;
    puVar5 = (undefined4 *)(uVar3 & 0xfffffff0);
    *DAT_00922214 = (uVar3 & 0xfffffff0) + 0x14;
    *puVar5 = 0;
    puVar5[1] = 0;
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar5[4] = 0;
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = 0;
      puVar5[1] = 0;
      puVar5[2] = 0;
      puVar5[3] = 0;
      puVar5[4] = 0;
      uVar4 = FUN_00513100(*(undefined4 *)(param_1 + 0x510),puVar1);
      puVar5[2] = uVar4;
      FUN_004f1310(DAT_0092221c + 0x50,puVar5);
      DAT_00922234 = puVar5 + 3;
      FUN_0052b9c0(param_1);
      DAT_00922234 = (undefined4 *)0x0;
    }
  }
  return;
}

