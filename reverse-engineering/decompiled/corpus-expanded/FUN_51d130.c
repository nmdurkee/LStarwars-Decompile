/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51d130; label: FUN_0051d130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051d130(code *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar2 = 0;
  if ((param_1 != (code *)0x0) && ((*(uint *)(unaff_ESI + 0x50) & 8) != 0)) {
    if ((*(uint *)(unaff_ESI + 0x50) & 4) == 0) {
      iVar3 = 0;
      if (*(char *)(unaff_ESI + 6) != '\0') {
        iVar4 = unaff_ESI + 0x54;
        do {
          if (*(char *)(iVar4 + 0x2d) != '\0') {
            iVar1 = (*param_1)();
            if (iVar1 != 0) break;
            if ((*(byte *)(iVar4 + 0x30) & 2) != 0) {
              iVar2 = 1;
            }
          }
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x34;
        } while (iVar3 < (int)(uint)*(byte *)(unaff_ESI + 6));
      }
    }
    else {
      iVar3 = *(byte *)(unaff_ESI + 6) - 1;
      if (-1 < iVar3) {
        iVar4 = iVar3 * 0x34 + 0x54 + unaff_ESI;
        do {
          if (*(char *)(iVar4 + 0x2d) != '\0') {
            iVar1 = (*param_1)();
            if (iVar1 != 0) break;
            if ((*(byte *)(iVar4 + 0x30) & 2) != 0) {
              iVar2 = 1;
            }
          }
          iVar3 = iVar3 + -1;
          iVar4 = iVar4 + -0x34;
          if (iVar3 < 0) {
            *(uint *)(unaff_ESI + 0x50) =
                 *(uint *)(unaff_ESI + 0x50) ^ (iVar2 << 4 ^ *(uint *)(unaff_ESI + 0x50)) & 0x10;
            return;
          }
        } while( true );
      }
    }
  }
  *(uint *)(unaff_ESI + 0x50) =
       *(uint *)(unaff_ESI + 0x50) ^ (iVar2 << 4 ^ *(uint *)(unaff_ESI + 0x50)) & 0x10;
  return;
}

