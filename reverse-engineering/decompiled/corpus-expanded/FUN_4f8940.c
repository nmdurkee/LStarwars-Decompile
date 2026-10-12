/* Ghidra pseudocode, not original source.
 * ev_1f7273160d1fc2c17e24c11295545580a626ef47c094abd3f1416147cfc2162d
 * Entry: 0x4f8940; label: FUN_004f8940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f8940(byte *param_1,byte *param_2,undefined1 *param_3)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  if (param_1 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (param_2 != (byte *)0x0) {
    bVar2 = *param_1;
    while (bVar2 != 0) {
      if (bVar2 == 0x2a) goto LAB_004f8a00;
      if (((byte)(bVar2 + 0x9f) < 0x1a) || (0xdf < bVar2)) {
        bVar2 = bVar2 - 0x20;
      }
      bVar4 = *param_2;
      if (((byte)(bVar4 + 0x9f) < 0x1a) || (0xdf < bVar4)) {
        bVar4 = bVar4 - 0x20;
      }
      if ((char)bVar4 < (char)bVar2) {
        return 1;
      }
      if ((char)bVar2 < (char)bVar4) {
        return 0xffffffff;
      }
      pbVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      bVar2 = *pbVar1;
    }
    if (*param_1 == 0x2a) {
LAB_004f8a00:
      param_1 = param_1 + 1;
      FUN_004f1ff0(param_1);
      uVar8 = FUN_004f1ff0(param_2);
      iVar3 = (int)uVar8 - (int)((ulonglong)uVar8 >> 0x20);
      if (iVar3 < 0) {
        return 1;
      }
      if (param_3 != (undefined1 *)0x0) {
        iVar6 = 0;
        if (0 < iVar3) {
          puVar5 = param_3;
          iVar7 = iVar3;
          do {
            *puVar5 = puVar5[(int)param_2 - (int)param_3];
            puVar5 = puVar5 + 1;
            iVar7 = iVar7 + -1;
            iVar6 = iVar3;
          } while (iVar7 != 0);
        }
        param_3[iVar6] = 0;
      }
      param_2 = param_2 + iVar3;
    }
    else if (param_3 != (undefined1 *)0x0) {
      *param_3 = 0;
    }
    bVar2 = *param_1;
    while( true ) {
      if (bVar2 == 0) {
        return 0;
      }
      if (((byte)(bVar2 + 0x9f) < 0x1a) || (0xdf < bVar2)) {
        bVar2 = bVar2 - 0x20;
      }
      bVar4 = *param_2;
      if (((byte)(bVar4 + 0x9f) < 0x1a) || (0xdf < bVar4)) {
        bVar4 = bVar4 - 0x20;
      }
      if ((char)bVar4 < (char)bVar2) break;
      if ((char)bVar2 < (char)bVar4) {
        return 0xffffffff;
      }
      bVar2 = param_1[1];
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  }
  return 1;
}

