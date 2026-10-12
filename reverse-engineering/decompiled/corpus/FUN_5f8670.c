/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8670; label: FUN_005f8670
 */

void FUN_005f8670(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = &DAT_00986f2c;
  do {
    if (((((&DAT_0280d7e0)[iVar2] != '\0') && (piVar1[-7] == 1)) && (*piVar1 == -1)) &&
       ((piVar1[-0xb] == 0 && (piVar1[-1] == 0)))) {
      FUN_005f81f0(piVar1 + -0xb,(short)piVar1[-10],*(undefined2 *)((int)piVar1 + -0x26),
                   *(undefined2 *)((int)piVar1 + -0x22),piVar1[-5],piVar1[-4],piVar1[-6]);
    }
    piVar1 = piVar1 + 0xc;
    iVar2 = iVar2 + 1;
  } while (piVar1 != (int *)&DAT_0098752c);
  return;
}

