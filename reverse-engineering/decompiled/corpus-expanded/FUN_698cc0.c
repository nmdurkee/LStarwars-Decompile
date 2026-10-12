/* Ghidra pseudocode, not original source.
 * ev_4289758b99e4c7501e635d810a16af61d296f1bd933ef263ce76cab568b7549e
 * Entry: 0x698cc0; label: FUN_00698cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00698cc0(void)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int iVar5;
  int iStack_8;
  byte local_4 [4];
  
  _DAT_02972c1c = 0;
  _DAT_02972c20 = 0;
  DVar2 = timeGetTime();
  DAT_02972c18 = DVar2 & 0x7fffffff;
  iVar5 = 0x20;
  piVar4 = (int *)(in_ECX + 0x68c);
  do {
    piVar1 = (int *)*piVar4;
    if (piVar1 != (int *)0x0) {
      _DAT_02972c1c = _DAT_02972c1c + 1;
      (**(code **)(*piVar1 + 0x24))(piVar1,local_4);
      if ((piVar4[5] != 0) && ((local_4[0] & 4) != 0)) {
        iVar3 = DAT_02972c18 - piVar4[10];
        if (iVar3 < 0) {
          iVar3 = iVar3 + -0x80000000;
        }
        *(bool *)((int)piVar4 + 0x19) = piVar4[0xb] < iVar3;
        if (piVar4[0xb] < iVar3) {
          iStack_8 = 0;
          (**(code **)(*(int *)*piVar4 + 0x18))((int *)*piVar4,&iStack_8);
          iVar3 = FUN_006e6b90();
          iStack_8 = iStack_8 + iVar3;
          if (iStack_8 < -7000) {
            FUN_00697690(iVar5);
          }
          else {
            FUN_00696b40(*piVar4,iStack_8);
          }
        }
        *(undefined1 *)(piVar4 + 6) = 0;
      }
    }
    iVar5 = iVar5 + 1;
    piVar4 = piVar4 + 0xd;
  } while (iVar5 < 0x40);
  piVar4 = (int *)(in_ECX + 0xc);
  iVar5 = 0x20;
  do {
    piVar1 = (int *)*piVar4;
    if (piVar1 != (int *)0x0) {
      _DAT_02972c20 = _DAT_02972c20 + 1;
      (**(code **)(*piVar1 + 0x24))(piVar1,local_4);
      if ((local_4[0] & 1) == 0) {
        if (*piVar4 != 0) {
          piVar1 = (int *)piVar4[1];
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          (**(code **)(*(int *)*piVar4 + 0x48))((int *)*piVar4);
          (**(code **)(*(int *)*piVar4 + 8))((int *)*piVar4);
          *piVar4 = 0;
          piVar4[1] = 0;
          *(int *)(in_ECX + 0xd10) = *(int *)(in_ECX + 0xd10) + -1;
        }
        _memset(piVar4,0,0x34);
      }
    }
    piVar4 = piVar4 + 0xd;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}

