/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d9ed0; label: FUN_004d9ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d9ed0(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float local_8;
  
  iVar2 = (int)*(short *)(*(int *)(DAT_029130e4 + 0x1c) + DAT_007f1b14 * 2);
  if ((iVar2 == -1) ||
     (iVar2 = *(int *)(*(int *)(DAT_029130e4 + 0x18) + 0xc + iVar2 * 0x54), *(int *)(iVar2 + 4) == 0
     )) {
    local_8 = 0.0;
    fVar1 = 0.0;
    iVar2 = 0;
  }
  else {
    fVar1 = **(float **)(iVar2 + 4);
    iVar2 = 0;
    local_8 = fVar1;
  }
  do {
    *(undefined4 *)((int)&DAT_0087b8f4 + iVar2) = 0;
    *(undefined4 *)((int)&DAT_0087b8ec + iVar2) = 0;
    *(undefined4 *)((int)&DAT_007fc198 + iVar2) = 0x3f800000;
    if (0.0 < fVar1) {
      iVar3 = FUN_0054fa60();
      *(float *)((int)&DAT_007fc198 + iVar2) =
           *(float *)((int)&DAT_007fc198 + iVar2) + (local_8 - 1.0) * (float)iVar3 * 1.5259022e-05;
      fVar1 = local_8;
    }
    iVar2 = iVar2 + 4;
  } while (iVar2 < 8);
  return;
}

