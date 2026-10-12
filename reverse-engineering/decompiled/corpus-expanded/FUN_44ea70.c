/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44ea70; label: FUN_0044ea70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0044ea70(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  uint local_4;
  
  iVar7 = 0;
  bVar1 = false;
  iVar6 = 0;
  bVar2 = false;
  local_4 = 0;
  bVar3 = false;
  if (((in_stack_00000018 != 0) && (in_stack_00000014 != 0)) && (0 < in_stack_00000014)) {
    do {
      iVar4 = FUN_004f8a70(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),"name=");
      if (iVar4 == 0) {
        iVar4 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),"backwards");
        if (iVar4 == 0) {
          bVar2 = true;
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),"stayopen");
          if (iVar4 == 0) {
            local_4 = 1;
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),"stayshut");
            if (iVar4 == 0) {
              bVar1 = true;
            }
            else {
              iVar4 = FUN_004f8b10(*(undefined4 *)(in_stack_00000010 + iVar7 * 4),&DAT_00757e88);
              if (iVar4 == 0) {
                bVar3 = true;
              }
            }
          }
        }
      }
      else {
        piVar5 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,
                                     iVar4 + 5);
        if (piVar5 != (int *)0x0) {
          iVar6 = *piVar5;
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < in_stack_00000014);
    if (iVar6 != 0) {
      if ((bVar2) || (bVar1)) {
        if (bVar3) {
          FUN_00558970();
        }
        else {
          FUN_005579d0(iVar6);
        }
      }
      else if (bVar3) {
        FUN_00558990();
      }
      else {
        FUN_00557960(iVar6);
      }
      *(uint *)(iVar6 + 0x9c) =
           ((uint)bVar1 * 2 | local_4) * 4 | *(uint *)(iVar6 + 0x9c) & 0xfffffff3;
    }
  }
  return 1;
}

