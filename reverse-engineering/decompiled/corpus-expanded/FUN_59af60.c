/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59af60; label: FUN_0059af60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059af60(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  float10 fVar4;
  
  cVar1 = FUN_006218c0();
  if (cVar1 != '\0') {
    FUN_00621900(param_1);
    fVar4 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0xc) = (float)fVar4;
    fVar4 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x10) = (float)fVar4;
    fVar4 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x14) = (float)fVar4;
    fVar4 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x18) = (float)fVar4;
    fVar4 = (float10)FUN_006217a0();
    *(float *)(param_1 + 0x1c) = (float)fVar4;
    uVar3 = FUN_00621860();
    *(undefined2 *)(param_1 + 0x20) = uVar3;
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x22) = uVar2;
    uVar2 = FUN_006218c0();
    *(undefined1 *)(param_1 + 0x23) = uVar2;
  }
  return;
}

