/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a1480; label: FUN_005a1480
 */

void FUN_005a1480(int param_1,float *param_2)

{
  float fVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_40 [12];
  float local_10;
  float local_c;
  float local_8;
  
  if (param_1 != 0) {
    for (puVar2 = *(undefined4 **)(param_1 + 0x18); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if ((*(byte *)(puVar2 + 8) & 4) == 0) {
        puVar3 = (undefined4 *)FUN_005cfa20(puVar2 + 1);
        if (puVar3 != (undefined4 *)0x0) {
          fVar1 = *param_2;
          puVar5 = local_40;
          for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
          }
          local_10 = fVar1 + local_10;
          local_c = param_2[1] + local_c;
          local_8 = param_2[2] + local_8;
          FUN_005ea570(puVar2 + 1,local_40);
        }
      }
    }
  }
  return;
}

