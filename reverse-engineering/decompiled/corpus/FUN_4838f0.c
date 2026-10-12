/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x4838f0; label: FUN_004838f0
 */

void FUN_004838f0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 != 0) {
    if ((*(int *)(iVar1 + 0x14) == -1) && (*(float *)(iVar1 + 0x18) < *(float *)(param_1 + 0x68))) {
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 2;
      return;
    }
    if (iVar1 != 0) {
      *(undefined1 *)(iVar1 + 0x12) = 1;
    }
  }
  *(char *)(param_1 + 0xb8) = *(char *)(param_1 + 0xb8) + '\x01';
  cVar3 = *(char *)(param_1 + 0xb8);
  *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x120);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x124);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x128);
  iVar1 = (int)*(char *)(cVar3 + 0xc9 + param_1);
  do {
    iVar1 = FUN_00483690(iVar1);
LAB_0048396c:
    *(int *)(param_1 + 0x128) = iVar1;
    if (*(int *)(param_1 + 0x124) == 0) {
      if (*(int *)(param_1 + 0x128) != 0) {
        *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x128);
        *(undefined4 *)(param_1 + 0x128) = 0;
      }
    }
    else if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x124);
      if (iVar1 != 0) {
        *(undefined4 *)(iVar1 + 0x14) = 0xffffffff;
        *(undefined4 *)(iVar1 + 0x18) = 0;
        *(undefined1 *)(iVar1 + 0x12) = 0;
        *(undefined4 *)(iVar1 + 0x1c) = 0x3f800000;
      }
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) & 0xfffffffd;
      DAT_0087a604 = 0;
      iVar1 = *(int *)(param_1 + 0x124);
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0xc) == 0xb)) || (*(int *)(iVar1 + 0xc) == 10)) {
        FUN_0054a7f0(param_1 + 0x24);
        FUN_0054a7f0(param_1 + 0x38);
      }
      if ((*(int *)(param_1 + 0x124) != 0) && (*(int *)(*(int *)(param_1 + 0x124) + 0xc) == 0xb)) {
        FUN_0042b080();
        return;
      }
      return;
    }
    cVar3 = cVar3 + '\x01';
    *(char *)(param_1 + 0xb8) = cVar3;
    if (cVar3 + 1 < (int)(uint)*(byte *)(param_1 + 0xb7)) {
      iVar1 = 0;
      if (*(int *)(DAT_0087a600 + 0xc) != -1) {
        iVar2 = *(int *)(DAT_0087a600 + 0xc);
        do {
          if (iVar2 == *(char *)(cVar3 + 0xc9 + param_1)) {
            iVar1 = iVar1 * 0x20 + DAT_0087a600;
            goto LAB_0048396c;
          }
          iVar1 = iVar1 + 1;
          iVar2 = *(int *)(iVar1 * 0x20 + 0xc + DAT_0087a600);
        } while (iVar2 != -1);
      }
      iVar1 = 0;
      goto LAB_0048396c;
    }
    iVar1 = 10;
  } while( true );
}

