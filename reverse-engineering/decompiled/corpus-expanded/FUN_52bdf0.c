/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52bdf0; label: FUN_0052bdf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052bdf0(int param_1)

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
      FUN_004f1310(DAT_0092221c + 0x48,puVar5);
      DAT_00922230 = puVar5 + 3;
      DAT_00922238 = 1;
      FUN_0052b3f0(param_1);
      DAT_00922230 = (undefined4 *)0x0;
      DAT_00922238 = 0;
    }
  }
  return;
}

