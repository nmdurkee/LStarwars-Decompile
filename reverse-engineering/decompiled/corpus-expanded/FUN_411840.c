/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x411840; label: FUN_00411840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00411840(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  
  if (*(int *)(in_EAX + 0x668) != 0) {
    iVar1 = in_EAX + 0x40;
    iVar2 = 5;
    do {
      if (*(int *)(iVar1 + 0x110) != 0) {
        FUN_00411470(iVar1);
      }
      iVar1 = iVar1 + 0x130;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

