/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575820; label: FUN_00575820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00575820(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 local_c [2];
  undefined4 local_4;
  
  _DAT_00951418 = 0;
  if (DAT_009513b8 != '\0') {
    iVar5 = *(int *)(PTR_DAT_00802c54 + 0x4698);
    if ((iVar5 != 0) &&
       (iVar6 = 0, puVar3 = PTR_DAT_00802c54, 0 < *(int *)(PTR_DAT_00802c54 + 0x469c))) {
      do {
        if ((*(int *)(iVar5 + 0xa0) != 0) &&
           (iVar2 = FUN_004f8b10(iVar5,&DAT_009513b8), puVar3 = PTR_DAT_00802c54, iVar2 == 0)) {
          iVar2 = 5;
          piVar7 = &DAT_0093d5a0;
          iVar6 = 0x30;
          do {
            if (iVar2 < **(short **)(iVar5 + 0xa0)) {
              iVar4 = *(int *)(*(short **)(iVar5 + 0xa0) + 4) + iVar6;
              *piVar7 = iVar4;
              FUN_005b3800(local_c,*(int *)(*(int *)(iVar5 + 0xa0) + 8) + 0xc + iVar6,iVar4);
              uVar1 = FUN_005be2d0(local_c[0],local_4);
            }
            else {
              uVar1 = (undefined2)piVar7[-1];
              *piVar7 = piVar7[-4];
            }
            *(undefined2 *)(piVar7 + 3) = uVar1;
            iVar6 = iVar6 + 0x18;
            iVar2 = iVar2 + 2;
            piVar7 = piVar7 + 4;
          } while (iVar6 < 0xf0);
          _DAT_00951418 = 1;
          return 1;
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x128;
      } while (iVar6 < *(int *)(puVar3 + 0x469c));
    }
    DAT_009513b8 = '\0';
  }
  return 0;
}

