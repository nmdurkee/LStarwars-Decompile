/* Ghidra pseudocode, not original source.
 * ev_d6e6804647628cd3e7ce0eee802958277deb78ba643873a9983999f38b8fc9a0
 * Entry: 0x6ded20; label: FUN_006ded20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ded20(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)&DAT_00827940;
  uVar2 = FUN_004f5240();
  switch(uVar2) {
  case 2:
    piVar3 = (int *)&DAT_00827a80;
    break;
  case 3:
    piVar3 = (int *)&DAT_00827e40;
    break;
  case 4:
    piVar3 = (int *)&DAT_00827bc0;
    break;
  case 5:
    piVar3 = (int *)&DAT_00827d00;
    break;
  case 8:
    piVar3 = (int *)&DAT_00827f80;
    break;
  case 0x12:
    piVar3 = &DAT_00827800;
  }
  _memset(&DAT_0297ad80,0,0x9c);
  iVar1 = piVar3[1];
  while (iVar1 != 0) {
    *(int *)(&DAT_0297ad80 + *piVar3 * 4) = iVar1;
    iVar1 = piVar3[3];
    piVar3 = piVar3 + 2;
  }
  DAT_0297ae1c = 1;
  return;
}

