/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x576c60; label: FUN_00576c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00576c60(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  if ((param_1 == 6) || (param_1 == 7)) {
    uVar5 = (uint)DAT_00951880;
    do {
      if ((&DAT_00951500)[uVar5 * 7] == param_1) {
        if (*(int *)(&DAT_00951508 + uVar5 * 0x1c) == param_3) {
          return;
        }
        uVar5 = 0xffffffff;
      }
      uVar5 = uVar5 - 1;
    } while (-1 < (int)uVar5);
  }
  if (DAT_00951880 == 0x20) {
    return;
  }
  switch(param_1) {
  case 1:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 1;
    goto LAB_00576cde;
  default:
    goto switchD_00576cc0_caseD_2;
  case 3:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 3;
    goto LAB_00576cde;
  case 4:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 4;
    goto LAB_00576cde;
  case 5:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 5;
    goto LAB_00576cde;
  case 6:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 6;
    break;
  case 7:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 7;
    break;
  case 8:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 8;
    goto LAB_00576f8c;
  case 9:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 9;
LAB_00576cde:
    (&DAT_00951504)[(uint)DAT_00951880 * 7] = param_2;
    *(undefined4 *)(&DAT_00951508 + (uint)DAT_00951880 * 0x1c) = 0;
    goto LAB_00576d10;
  case 10:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 10;
    break;
  case 0xb:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 0xb;
    break;
  case 0xc:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 0xc;
    break;
  case 0xd:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 0xd;
    break;
  case 0xe:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 0xe;
    break;
  case 0xf:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 0xf;
    break;
  case 0x10:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 0x10;
    (&DAT_00951504)[(uint)DAT_00951880 * 7] = 0;
    *(undefined4 *)(&DAT_00951508 + (uint)DAT_00951880 * 0x1c) = 0;
    uVar5 = (uint)DAT_00951880;
    puVar4 = (undefined4 *)(&DAT_0095150c + uVar5 * 0x1c);
    *puVar4 = param_5;
    *(undefined4 *)(&DAT_00951510 + uVar5 * 0x1c) = param_6;
    goto LAB_00576d3e;
  case 0x11:
    (&DAT_00951500)[(uint)DAT_00951880 * 7] = 0x11;
LAB_00576f8c:
    (&DAT_00951504)[(uint)DAT_00951880 * 7] = 0;
    *(undefined4 *)(&DAT_00951508 + (uint)DAT_00951880 * 0x1c) = 0;
    uVar2 = DAT_0093b0d0;
    iVar1 = (uint)DAT_00951880 * 0x1c;
    *(undefined4 *)(&DAT_0095150c + iVar1) = DAT_0093b0cc;
    uVar3 = DAT_0093b0d4;
    *(undefined4 *)(&DAT_00951510 + iVar1) = uVar2;
    *(undefined4 *)(&DAT_00951514 + iVar1) = uVar3;
    *(undefined4 *)(&DAT_00951518 + (uint)DAT_00951880 * 0x1c) = param_4;
switchD_00576cc0_caseD_2:
    DAT_00951880 = DAT_00951880 + 1;
    return;
  }
  (&DAT_00951504)[(uint)DAT_00951880 * 7] = 0;
  *(int *)(&DAT_00951508 + (uint)DAT_00951880 * 0x1c) = param_3;
LAB_00576d10:
  uVar5 = (uint)DAT_00951880;
  puVar4 = (undefined4 *)(&DAT_0095150c + uVar5 * 0x1c);
  *puVar4 = DAT_0093b0cc;
  *(undefined4 *)(&DAT_00951510 + uVar5 * 0x1c) = DAT_0093b0d0;
  param_7 = DAT_0093b0d4;
LAB_00576d3e:
  puVar4[2] = param_7;
  *(undefined4 *)(&DAT_00951518 + (uint)DAT_00951880 * 0x1c) = 0;
  DAT_00951880 = DAT_00951880 + 1;
  return;
}

