/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51d310; label: FUN_0051d310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0051d310(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar5;
  float local_c;
  int local_4;
  
  local_c = 3.4028235e+38;
  iVar4 = 4;
  local_4 = 4;
  if ((*(char *)(unaff_EDI + 0x7a) == '\0') || ((*(byte *)(unaff_ESI + 0x1ec) & 4) == 0)) {
    if (*(byte *)(unaff_EDI + 0x10) <= *(byte *)(unaff_ESI + 0x143)) {
      *(undefined1 *)(unaff_ESI + 0x143) = 0xff;
    }
    if (*(byte *)(unaff_EDI + 0x10) <= *(byte *)(unaff_ESI + 0x142)) {
      *(undefined1 *)(unaff_ESI + 0x142) = 0;
    }
    if (*(byte *)(unaff_ESI + 0x143) < *(byte *)(unaff_EDI + 0x10)) {
      fVar5 = (float10)FUN_005b3c50((uint)*(byte *)(unaff_ESI + 0x143) * 0x5c + 4 +
                                    *(int *)(unaff_EDI + 0x7c),param_1,0);
      local_c = (float)fVar5;
    }
    do {
      fVar5 = (float10)FUN_005b3c50((uint)*(byte *)(unaff_ESI + 0x142) * 0x5c + 4 +
                                    *(int *)(unaff_EDI + 0x7c),param_1,0);
      if ((float)fVar5 < local_c) {
        *(undefined1 *)(unaff_ESI + 0x143) = *(undefined1 *)(unaff_ESI + 0x142);
        local_c = (float)fVar5;
      }
      *(char *)(unaff_ESI + 0x142) = *(char *)(unaff_ESI + 0x142) + '\x01';
      if (*(byte *)(unaff_EDI + 0x10) < *(byte *)(unaff_ESI + 0x142)) {
        *(undefined1 *)(unaff_ESI + 0x142) = 0;
      }
      iVar4 = iVar4 + -1;
    } while (0 < iVar4);
  }
  else {
    iVar4 = *(int *)(unaff_EDI + 0x8c);
    if (*(byte *)(unaff_EDI + 0x10) <= *(byte *)(unaff_ESI + 0x143)) {
      *(undefined1 *)(unaff_ESI + 0x143) = 0xff;
    }
    if (*(byte *)(unaff_EDI + 0x7a) <= *(byte *)(unaff_ESI + 0x142)) {
      *(undefined1 *)(unaff_ESI + 0x142) = 0;
    }
    if (*(byte *)(unaff_ESI + 0x143) < *(byte *)(unaff_EDI + 0x10)) {
      fVar5 = (float10)FUN_005b3c50((uint)*(byte *)(unaff_ESI + 0x143) * 0x5c + 4 +
                                    *(int *)(unaff_EDI + 0x7c),param_1,0);
      local_c = (float)fVar5;
    }
    bVar3 = *(byte *)(unaff_ESI + 0x142);
    uVar1 = (uint)bVar3;
    uVar2 = uVar1;
    while( true ) {
      if (*(byte *)(unaff_ESI + 0x143) != bVar3) {
        fVar5 = (float10)FUN_005b3c50((uint)*(byte *)(iVar4 + uVar2 * 4) * 0x5c + 4 +
                                      *(int *)(unaff_EDI + 0x7c),param_1,0);
        if ((float)fVar5 < local_c) {
          *(undefined1 *)(unaff_ESI + 0x143) =
               *(undefined1 *)(iVar4 + (uint)*(byte *)(unaff_ESI + 0x142) * 4);
          local_c = (float)fVar5;
        }
      }
      *(char *)(unaff_ESI + 0x142) = *(char *)(unaff_ESI + 0x142) + '\x01';
      if (*(byte *)(unaff_EDI + 0x7a) < *(byte *)(unaff_ESI + 0x142)) {
        *(undefined1 *)(unaff_ESI + 0x142) = 0;
      }
      local_4 = local_4 + -1;
      if (local_4 < 1) break;
      bVar3 = *(byte *)(unaff_ESI + 0x142);
      uVar2 = (uint)bVar3;
      if (uVar2 == uVar1) {
        return;
      }
    }
  }
  return;
}

