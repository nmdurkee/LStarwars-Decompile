/* Ghidra pseudocode, not original source.
 * ev_af5fdeed9a437c46ff08a54f0cc4a72e038853601385fcc42f544dd0663c9d10
 * Entry: 0x635e40; label: FUN_00635e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00635e40(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *_Dst;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  _Dst = (undefined4 *)(*param_2 + 3U & 0xfffffffc);
  *param_2 = (int)_Dst;
  _memset(_Dst,0,0x4f84);
  FUN_004fd5d0(param_1,*param_2,param_3 - *param_2);
  switch(*_Dst) {
  case 1:
    FUN_00633df0(param_1);
    break;
  case 2:
    puVar1 = _Dst + 0x8d9;
    _Dst[0x8c8] = 0x41200000;
    iVar5 = 0x1f;
    _Dst[0x8cb] = 0;
    _Dst[0x8ca] = 0;
    _Dst[0x8c9] = 0;
    _Dst[0x8c6] = 1;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 0x13;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  case 3:
    iVar5 = 0x20;
    puVar1 = _Dst + 0x13e1;
    do {
      iVar5 = iVar5 + -1;
      puVar6 = puVar1 + -0x8d3;
      puVar7 = puVar1 + -0x13;
      for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      puVar1 = puVar1 + -0x13;
    } while (iVar5 != 0);
    puVar1 = _Dst + 0x8d7;
    iVar5 = 0x40;
    do {
      *(undefined1 *)puVar1 = 0;
      puVar1 = puVar1 + 0x23;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  case 4:
    puVar2 = (undefined1 *)((int)_Dst + 0x7e);
    iVar5 = 0x80;
    do {
      *(undefined4 *)(puVar2 + -0xe) = 0x3f800000;
      puVar2[-1] = 0xff;
      *puVar2 = 0xff;
      puVar2[1] = 0;
      puVar2 = puVar2 + 0x8c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  default:
    piVar3 = _Dst + 0x20;
    iVar5 = 0x80;
    do {
      *(short *)((int)piVar3 + -0x12) = DAT_0080fdfc;
      DAT_0080fdfc = DAT_0080fdfc + 1;
      if (DAT_0080fdfc == 0) {
        DAT_0080fdfc = 1;
      }
      *piVar3 = (int)(_Dst + 1);
      piVar3 = piVar3 + 0x23;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  *_Dst = DAT_0080fde8;
  *param_2 = *param_2 + 0x4f84;
  FUN_00635b10(_Dst,param_2,param_3);
  return _Dst;
}

