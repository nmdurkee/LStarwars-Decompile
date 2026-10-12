/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da520; label: FUN_005da520
 */

undefined4 FUN_005da520(ushort *param_1,byte *param_2,undefined1 *param_3,float param_4)

{
  undefined1 uVar1;
  byte *extraout_ECX;
  ushort *extraout_EDX;
  byte bVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar3 = (float10)param_4;
  bVar2 = *param_2;
  if (((ushort)bVar2 < *param_1) &&
     (fVar4 = (float10)*(float *)(*(int *)(param_1 + 2) + (uint)bVar2 * 4),
     fVar4 < fVar3 != (fVar4 == fVar3))) {
    do {
      *param_3 = *(undefined1 *)((uint)*param_2 + *(int *)(param_1 + 4));
      *param_2 = *param_2 + 1;
      if (*param_1 <= (ushort)*param_2) {
        return 1;
      }
      fVar4 = (float10)*(float *)(*(int *)(param_1 + 2) + (uint)*param_2 * 4);
    } while (fVar4 < fVar3 != (fVar4 == fVar3));
    return 1;
  }
  if ((bVar2 != 0) && (fVar3 < (float10)*(float *)(*(int *)(param_1 + 2) + -4 + (uint)bVar2 * 4))) {
    do {
      bVar2 = bVar2 - 1;
      *param_2 = bVar2;
      if (bVar2 == 0) {
        fVar3 = (float10)FUN_005c1300();
        uVar1 = **(undefined1 **)(extraout_EDX + 4);
        param_2 = extraout_ECX;
        param_1 = extraout_EDX;
      }
      else {
        uVar1 = *(undefined1 *)(*(int *)(param_1 + 4) + -1 + (uint)bVar2);
      }
      *param_3 = uVar1;
      bVar2 = *param_2;
    } while ((bVar2 != 0) &&
            (fVar3 < (float10)*(float *)(*(int *)(param_1 + 2) + -4 + (uint)bVar2 * 4)));
    return 1;
  }
  return 0;
}

