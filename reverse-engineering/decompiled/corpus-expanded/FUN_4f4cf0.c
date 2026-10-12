/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f4cf0; label: FUN_004f4cf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f4cf0(byte *param_1)

{
  if (*param_1 != 0) {
    if ((DAT_0297dc08 == 2) && ((*(uint *)(param_1 + 0x10) & DAT_0297dc28) != 0)) {
      DAT_0297dc08 = 0;
    }
    if (((*param_1 != 0) && (DAT_0297dc08 == 1)) &&
       ((*(uint *)(param_1 + 0x10) & DAT_0297dc24) != 0)) {
      DAT_0297dc20 = 1;
    }
  }
  if (DAT_0297dc08 == 1) {
    *DAT_0297dc14 = (uint)*param_1;
    DAT_0297dc14 = DAT_0297dc14 + 1;
    if (*param_1 != 0) {
      *(byte *)DAT_0297dc14 = param_1[8];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(byte *)DAT_0297dc14 = param_1[9];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(byte *)DAT_0297dc14 = param_1[10];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(byte *)DAT_0297dc14 = param_1[0xb];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(byte *)DAT_0297dc14 = param_1[0xc];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(byte *)DAT_0297dc14 = param_1[0xd];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(byte *)DAT_0297dc14 = param_1[0xe];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(byte *)DAT_0297dc14 = param_1[0xf];
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *DAT_0297dc14 = *(undefined4 *)(param_1 + 0x10);
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 4);
    }
  }
  else if (DAT_0297dc08 == 2) {
    *param_1 = (byte)*DAT_0297dc14;
    DAT_0297dc14 = DAT_0297dc14 + 1;
    if (*param_1 != 0) {
      param_1[8] = (byte)*DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      param_1[9] = *(byte *)DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      param_1[10] = *(byte *)DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      param_1[0xb] = *(byte *)DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      param_1[0xc] = *(byte *)DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      param_1[0xd] = *(byte *)DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      param_1[0xe] = *(byte *)DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      param_1[0xf] = *(byte *)DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 1);
      *(uint *)(param_1 + 0x10) = *DAT_0297dc14;
      DAT_0297dc14 = (uint *)((int)DAT_0297dc14 + 4);
      return;
    }
  }
  return;
}

