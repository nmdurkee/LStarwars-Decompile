/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d8d60; label: FUN_006d8d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d8d60(int param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,int param_6,
                 int param_7,char *param_8)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  
  if (param_6 == 0) {
    iVar5 = param_2 * 0x17c + 0x4ea2;
  }
  else {
    iVar5 = param_7 * 0x80 + 0x6358;
  }
  bVar3 = param_2 < 4;
  iVar5 = iVar5 + in_ECX;
  cVar1 = *(char *)(in_ECX + 0x67f0 + param_1 * 6);
  if ((param_3 == 5) || (param_3 == 6)) {
    uVar6 = 5;
    param_2 = 6;
  }
  else {
    uVar6 = 2;
    param_2 = 3;
  }
  if ((_DAT_0297591c & 1) == 0) {
    _DAT_0297591c = _DAT_0297591c | 1;
    DAT_02975916 = (undefined1)uVar6;
    DAT_02975918 = (undefined1)param_2;
    DAT_02975919 = (undefined1)param_2;
    DAT_0297591a = 0;
    DAT_0297591b = 0;
    DAT_02975917 = DAT_02975916;
  }
  if ((param_3 != uVar6) && (param_3 != param_2)) {
    iVar4 = 0;
    do {
      if (((*(byte *)(iVar5 + iVar4 * 4) == param_3) &&
          (*(short *)(iVar5 + 2 + iVar4 * 4) == param_4)) &&
         (((uint)param_8 & 1 << ((byte)iVar4 & 0x1f)) == 0)) {
        *(undefined1 *)(iVar5 + iVar4 * 4) = 0;
        *(undefined2 *)(iVar5 + 2 + iVar4 * 4) = 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    *(ushort *)(iVar5 + 2 + param_1 * 4) = (ushort)param_4;
    *(undefined1 *)(iVar5 + param_1 * 4) = (undefined1)param_3;
    return;
  }
  if (cVar1 == '\x03') {
    *(undefined1 *)(iVar5 + param_1 * 4) = (undefined1)param_3;
    iVar4 = 0;
    param_8 = (char *)(in_ECX + 0x67f0);
    *(ushort *)(iVar5 + 2 + param_1 * 4) = (ushort)param_4;
    do {
      if (((iVar4 != param_1) &&
          ((uVar7 = (uint)*(byte *)(iVar5 + iVar4 * 4), uVar7 == uVar6 || (uVar7 == param_2)))) &&
         (*(short *)(iVar5 + 2 + iVar4 * 4) == param_4)) {
        iVar9 = 0;
        if (param_3 == uVar6) {
          iVar9 = 4;
        }
        if (uVar7 == uVar6) {
          iVar9 = iVar9 + 2;
        }
        if (*param_8 == '\x02') {
          iVar9 = iVar9 + 1;
        }
        if (*param_8 == '\x03') {
          iVar9 = iVar9 + 8;
        }
        cVar1 = *(char *)(iVar9 + 0x297590c);
        *(char *)(iVar5 + iVar4 * 4) = cVar1;
        *(ushort *)(iVar5 + 2 + iVar4 * 4) = -(ushort)(cVar1 != '\0') & (ushort)param_4;
      }
      param_8 = param_8 + 6;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    return;
  }
  uVar7 = uVar6;
  if (((param_3 != uVar6) || (cVar1 != '\x02')) && ((param_3 != param_2 || (cVar1 != '\x01')))) {
    param_3 = param_2;
    uVar7 = param_3;
  }
  param_3 = uVar7;
  iVar4 = 0;
  do {
    uVar7 = (uint)*(byte *)(iVar5 + iVar4 * 4);
    if ((((uVar7 == uVar6) || (uVar7 == param_2)) && (*(short *)(iVar5 + 2 + iVar4 * 4) == param_4))
       && (((uint)param_8 & 1 << ((byte)iVar4 & 0x1f)) == 0)) {
      *(undefined1 *)(iVar5 + iVar4 * 4) = 0;
      *(undefined2 *)(iVar5 + 2 + iVar4 * 4) = 0;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x20);
  cVar2 = *(char *)(in_ECX + param_1 * 6 + 0x67f1);
  if (-1 < cVar2) {
    if ((bVar3) && ((param_4 == 6 || (param_4 == 7)))) {
      *(ushort *)(iVar5 + 2 + param_1 * 4) = (ushort)param_4;
      *(undefined1 *)(iVar5 + param_1 * 4) = (undefined1)param_3;
      return;
    }
    if ((cVar1 == '\x02') || (cVar1 == '\x01')) {
      iVar4 = 0;
      pcVar8 = (char *)(in_ECX + 0x67f0);
      do {
        if (((*pcVar8 == '\x02') || (*pcVar8 == '\x01')) && (pcVar8[1] == cVar2)) {
          *(undefined1 *)(iVar5 + iVar4 * 4) = (undefined1)param_3;
          *(ushort *)(iVar5 + 2 + iVar4 * 4) = (ushort)param_4;
        }
        iVar4 = iVar4 + 1;
        pcVar8 = pcVar8 + 6;
      } while (iVar4 < 0x20);
    }
  }
  return;
}

