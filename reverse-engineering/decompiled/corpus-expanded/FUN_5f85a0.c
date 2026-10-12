/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f85a0; label: FUN_005f85a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f85a0(void)

{
  int *piVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iStack_8;
  
  iVar4 = 0;
  piVar3 = &DAT_00986f00;
  do {
    if (((&DAT_0280d7e0)[iVar4] != '\0') && (piVar3[0xb] == -1)) {
      piVar1 = (int *)*piVar3;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar3 = 0;
      }
      piVar1 = (int *)piVar3[10];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        piVar3[10] = 0;
      }
      if (*(short *)((int)piVar3 + 10) == 1) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = 1.5;
      }
      iStack_8 = (int)(longlong)
                      ROUND((float)(int)((uint)*(ushort *)((int)piVar3 + 6) *
                                         (uint)*(ushort *)(piVar3 + 1) * -4) * fVar2);
      DAT_02854bc0 = DAT_02854bc0 + iStack_8;
    }
    piVar3 = piVar3 + 0xc;
    iVar4 = iVar4 + 1;
  } while (piVar3 != (int *)&DAT_00987500);
  return;
}

