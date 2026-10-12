/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69f190; label: FUN_0069f190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined8 FUN_0069f190(int *param_1,undefined4 *param_2)

{
  byte bVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 extraout_EDX;
  int iVar7;
  int iVar8;
  int iVar9;
  
  piVar2 = param_1;
  iVar9 = param_1[7];
  if (0xff < iVar9) {
    iVar9 = 0xff;
  }
  uVar4 = 0xffffffff;
  uVar3 = 0xff;
  iVar7 = 0;
  iVar8 = 0;
  param_1 = (int *)0x0;
  if (iVar9 == 0) {
    return 0xffffffff00000000;
  }
  if (piVar2[0x53] == 0) {
    uVar3 = 0;
    if (0 < iVar9) {
      puVar5 = (uint *)piVar2[4];
      do {
        iVar7 = iVar7 + 1;
        if ((*puVar5 & 0xff) < 0xff) break;
        puVar5 = puVar5 + 1;
      } while (iVar7 < iVar9);
    }
  }
  else if (0 < iVar9) {
    do {
      uVar3 = (undefined1)uVar4;
      if (0x1000 < iVar8) break;
      uVar6 = *(uint *)(piVar2[4] + iVar7 * 4) & 0xff;
      iVar8 = iVar8 + uVar6;
      if (uVar6 < 0xff) {
        uVar4 = *(undefined4 *)(piVar2[5] + iVar7 * 8);
      }
      uVar3 = (undefined1)uVar4;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar9);
  }
  piVar2[10] = 0x5367674f;
  *(undefined1 *)(piVar2 + 0xb) = 0;
  *(undefined1 *)((int)piVar2 + 0x2d) = 0;
  if ((*(uint *)piVar2[4] & 0x100) == 0) {
    *(undefined1 *)((int)piVar2 + 0x2d) = 1;
  }
  if (piVar2[0x53] == 0) {
    *(byte *)((int)piVar2 + 0x2d) = *(byte *)((int)piVar2 + 0x2d) | 2;
  }
  if ((piVar2[0x52] != 0) && (piVar2[7] == iVar7)) {
    *(byte *)((int)piVar2 + 0x2d) = *(byte *)((int)piVar2 + 0x2d) | 4;
  }
  piVar2[0x53] = 1;
  *(undefined1 *)((int)piVar2 + 0x2e) = uVar3;
  uVar3 = __allshr();
  *(undefined1 *)((int)piVar2 + 0x2f) = uVar3;
  uVar3 = __allshr();
  *(undefined1 *)(piVar2 + 0xc) = uVar3;
  uVar3 = __allshr();
  *(undefined1 *)((int)piVar2 + 0x31) = uVar3;
  uVar3 = __allshr();
  *(undefined1 *)((int)piVar2 + 0x32) = uVar3;
  uVar3 = __allshr();
  *(undefined1 *)((int)piVar2 + 0x33) = uVar3;
  uVar3 = __allshr();
  *(undefined1 *)(piVar2 + 0xd) = uVar3;
  uVar3 = __allshr();
  *(undefined1 *)((int)piVar2 + 0x35) = uVar3;
  iVar9 = piVar2[0x54];
  *(char *)((int)piVar2 + 0x36) = (char)iVar9;
  *(char *)((int)piVar2 + 0x37) = (char)((uint)iVar9 >> 8);
  *(char *)(piVar2 + 0xe) = (char)((uint)iVar9 >> 0x10);
  *(char *)((int)piVar2 + 0x39) = (char)((uint)iVar9 >> 0x18);
  if (piVar2[0x55] == -1) {
    piVar2[0x55] = 0;
  }
  iVar9 = piVar2[0x55];
  piVar2[0x55] = iVar9 + 1;
  *(char *)((int)piVar2 + 0x3a) = (char)iVar9;
  *(char *)((int)piVar2 + 0x3b) = (char)((uint)iVar9 >> 8);
  *(char *)(piVar2 + 0xf) = (char)((uint)iVar9 >> 0x10);
  *(char *)((int)piVar2 + 0x3d) = (char)((uint)iVar9 >> 0x18);
  iVar9 = 0;
  *(undefined1 *)((int)piVar2 + 0x3e) = 0;
  *(undefined1 *)((int)piVar2 + 0x3f) = 0;
  *(undefined1 *)(piVar2 + 0x10) = 0;
  *(undefined1 *)((int)piVar2 + 0x41) = 0;
  *(char *)((int)piVar2 + 0x42) = (char)iVar7;
  if (0 < iVar7) {
    do {
      bVar1 = *(byte *)(piVar2[4] + iVar9 * 4);
      param_1 = (int *)((int)param_1 + (uint)bVar1);
      *(byte *)((int)piVar2 + iVar9 + 0x43) = bVar1;
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar7);
  }
  *param_2 = piVar2 + 10;
  piVar2[0x51] = iVar7 + 0x1b;
  param_2[1] = iVar7 + 0x1b;
  iVar9 = piVar2[3];
  iVar8 = *piVar2;
  param_2[3] = param_1;
  param_2[2] = iVar9 + iVar8;
  piVar2[7] = piVar2[7] - iVar7;
  _memmove((void *)piVar2[4],(void *)(piVar2[4] + iVar7 * 4),piVar2[7] * 4);
  _memmove((void *)piVar2[5],(void *)(piVar2[5] + iVar7 * 8),piVar2[7] * 8);
  piVar2[3] = piVar2[3] + (int)param_1;
  FUN_0069ef50(param_2);
  return CONCAT44(extraout_EDX,1);
}

