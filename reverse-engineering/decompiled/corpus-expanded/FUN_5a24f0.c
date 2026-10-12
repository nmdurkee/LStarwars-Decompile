/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a24f0; label: FUN_005a24f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a24f0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined2 param_9,int param_10,undefined4 *param_11)

{
  undefined4 *puVar1;
  int extraout_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_10 != 0) && (param_1 != 0)) {
    puVar1 = (undefined4 *)FUN_005a2400();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = *(undefined4 **)(extraout_ECX + 0x10);
      *(undefined4 **)(extraout_ECX + 0xc) = puVar1;
      *(undefined4 *)(extraout_ECX + 0x10) = puVar1[0x1e];
    }
    else if (*(int *)(extraout_ECX + 0x10) == 0) {
      *(undefined4 **)(extraout_ECX + 0x10) = puVar1;
    }
    if (puVar1 != (undefined4 *)0x0) {
      puVar3 = puVar1;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = *param_2;
        param_2 = param_2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar1[0x15] = param_3;
      puVar1[0x16] = param_4;
      puVar1[0x14] = param_3;
      puVar1[0x1a] = 0;
      puVar1[0x1b] = param_5;
      puVar1[0x1c] = param_6;
      *(undefined2 *)(puVar1 + 0x1d) = param_9;
      puVar1[0x18] = param_7;
      puVar1[0x17] = param_7;
      puVar1[0x13] = param_10;
      puVar1[0x19] = param_8;
      if (param_11 != (undefined4 *)0x0) {
        puVar1[0x10] = *param_11;
        puVar1[0x11] = param_11[1];
        puVar1[0x12] = param_11[2];
        return;
      }
      puVar1[0x10] = DAT_0093b0cc;
      puVar1[0x11] = DAT_0093b0d0;
      puVar1[0x12] = DAT_0093b0d4;
    }
  }
  return;
}

