/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a1dd0; label: FUN_005a1dd0
 */

void FUN_005a1dd0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  float10 fVar6;
  float local_48;
  int local_44;
  undefined4 local_40 [12];
  undefined1 local_10 [16];
  
  iVar3 = *(int *)(param_1 + 0x5034);
  if ((iVar3 != 0) && (local_44 = 0, 0 < *(int *)(param_1 + 0x5038))) {
    iVar4 = iVar3 + 0xc;
    do {
      puVar1 = (undefined4 *)FUN_005d0330(iVar3);
      puVar5 = local_40;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar5 = puVar5 + 1;
      }
      iVar2 = FUN_005cfac0(iVar4);
      if (iVar2 == 0) {
        fVar6 = (float10)FUN_005becc0(local_10,DAT_00925164 + 0x30,0);
        fVar6 = (float10)(float)fVar6;
        if ((float10)0.5 <= fVar6) {
          if (fVar6 < (float10)2.0) {
            fVar6 = (fVar6 - (float10)0.5) / (float10)1.5;
            goto LAB_005a1e2e;
          }
          local_48 = 1.0;
          goto LAB_005a1e3f;
        }
      }
      else {
        fVar6 = (float10)FUN_00552820(iVar4);
        fVar6 = (float10)1 - fVar6;
LAB_005a1e2e:
        local_48 = (float)fVar6;
        if (0.0 < local_48) {
LAB_005a1e3f:
          FUN_005ff7a0(iVar3,local_40,local_48);
        }
      }
      local_44 = local_44 + 1;
      iVar3 = iVar3 + 0x18;
      iVar4 = iVar4 + 0x18;
    } while (local_44 < *(int *)(param_1 + 0x5038));
  }
  return;
}

