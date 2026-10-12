/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x455fb0; label: FUN_00455fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00455fb0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  iVar1 = 0;
  if ((in_stack_00000018 != 0) && (iVar4 = 0, 0 < in_stack_00000014)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"level=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar4 * 4),"cutscene=");
        if (iVar1 != 0) {
          iVar3 = FUN_004f1ff0("cutscene=");
          iVar3 = iVar3 + iVar1;
        }
      }
      else {
        iVar2 = FUN_004f1ff0("level=");
        local_4 = FUN_00578da0(iVar1 + iVar2,0);
      }
      iVar4 = iVar4 + 1;
      iVar1 = local_4;
    } while (iVar4 < in_stack_00000014);
  }
  if ((((DAT_0093b2a4 != 0) || (iVar3 == 0)) ||
      (iVar3 = FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),iVar3,0), iVar3 == 0)) &&
     (iVar1 != 0)) {
    FUN_0057a580((int)*(short *)(iVar1 + 0x62));
  }
  return 1;
}

