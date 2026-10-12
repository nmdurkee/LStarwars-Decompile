/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x455cc0; label: FUN_00455cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00455cc0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_8;
  char local_4;
  
  iVar6 = 0;
  local_4 = '\x01';
  local_8 = 0;
  if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
    iVar6 = **(int **)(param_3 + 0xd0);
  }
  if (param_6 != 0) {
    iVar7 = 0;
    iVar2 = 0;
    cVar1 = '\x01';
    if (0 < param_5) {
      do {
        local_4 = cVar1;
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"techno");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar7 * 4),"FALSE");
          if (iVar2 == 0) {
            local_4 = '\0';
          }
          else {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"controlling");
            if (iVar2 != 0) {
              iVar6 = FUN_004f1ff0("controlling");
              if ((DAT_00923904 == (code *)0x0) ||
                 (piVar5 = (int *)(*DAT_00923904)(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),
                                                  iVar2 + 1 + iVar6), piVar5 == (int *)0x0)) {
                iVar6 = 0;
              }
              else {
                iVar6 = *piVar5;
              }
            }
          }
        }
        else {
          iVar3 = FUN_004f1ff0("techno");
          uVar4 = FUN_00559e20(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),"Techno",iVar2 + 1 + iVar3
                              );
          piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),uVar4);
          if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
            local_8 = *piVar5;
          }
        }
        iVar7 = iVar7 + 1;
        iVar2 = local_8;
        cVar1 = local_4;
      } while (iVar7 < param_5);
    }
    if (iVar6 != 0) {
      iVar2 = FUN_004cca90(iVar6);
    }
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0x3c) =
           *(byte *)(iVar2 + 0x3c) ^ (local_4 << 3 ^ *(byte *)(iVar2 + 0x3c)) & 8;
      return 1;
    }
  }
  return 1;
}

