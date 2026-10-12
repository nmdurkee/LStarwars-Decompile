/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481f00; label: FUN_00481f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00481f00(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined1 local_40 [64];
  
  if ((*(int *)(param_1 + 0x50a8) != 0) && (iVar1 = 0, 0 < *(int *)(param_1 + 0x50ac))) {
    puVar2 = (undefined2 *)(*(int *)(param_1 + 0x50a8) + 0x14);
    do {
      if (((*(byte *)((int)puVar2 + 3) & 2) != 0) &&
         (*(char *)(*(short *)(&DAT_007fa378 + (uint)*(byte *)(puVar2 + 2) * 0x20) * 0x10 + 0xe +
                   *(int *)(param_1 + 0x2ac0)) != '\0')) {
        FUN_005b4670(local_40,*puVar2);
        FUN_005b4900(local_40,puVar2 + -6);
        FUN_005f33b0(*(short *)(&DAT_007fa378 + (uint)*(byte *)(puVar2 + 2) * 0x20) * 0x10 +
                     *(int *)(param_1 + 0x2ac0),local_40);
      }
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x1c;
    } while (iVar1 < *(int *)(param_1 + 0x50ac));
  }
  return;
}

