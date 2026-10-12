/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c320; label: FUN_0067c320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0067c320(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 param_5)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  if (((DAT_0292fc68 != (int *)0x0) && (DAT_0292fc68[0x54] < DAT_0292fc68[0x2921])) &&
     ((int)(short)DAT_0292fc68[0x53] < DAT_0292fc68[0x2922])) {
    *(undefined2 *)(*DAT_0292fc68 + 0x32 + (short)DAT_0292fc68[0x53] * 0x38) = 0xffff;
    *(undefined2 *)(*DAT_0292fc68 + 0x30 + (short)DAT_0292fc68[0x53] * 0x38) = 0xffff;
    puVar2 = (uint *)(*DAT_0292fc68 + 0x28 + (short)DAT_0292fc68[0x53] * 0x38);
    *puVar2 = *puVar2 & 0xfffffffe;
    *(undefined4 *)(*DAT_0292fc68 + 0x2c + (short)DAT_0292fc68[0x53] * 0x38) = 0;
    puVar1 = (undefined4 *)(*DAT_0292fc68 + (short)DAT_0292fc68[0x53] * 0x38);
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
    *(undefined4 *)(*DAT_0292fc68 + 0xc + (short)DAT_0292fc68[0x53] * 0x38) = param_2;
    puVar1 = (undefined4 *)(*DAT_0292fc68 + 0x10 + (short)DAT_0292fc68[0x53] * 0x38);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1 = (undefined4 *)(*DAT_0292fc68 + 0x1c + (short)DAT_0292fc68[0x53] * 0x38);
    *puVar1 = *param_4;
    puVar1[1] = param_4[1];
    puVar1[2] = param_4[2];
    *(undefined4 *)(*DAT_0292fc68 + 0x34 + (short)DAT_0292fc68[0x53] * 0x38) = param_5;
    *(short *)(DAT_0292fc68[0x6ed] + DAT_0292fc68[0x54] * 2) = (short)DAT_0292fc68[0x53];
    DAT_0292fc68[0x54] = DAT_0292fc68[0x54] + 1;
    *(short *)((int)DAT_0292fc68 + 0x1b9a) = *(short *)((int)DAT_0292fc68 + 0x1b9a) + 1;
    *(short *)(DAT_0292fc68 + 0x53) = (short)DAT_0292fc68[0x53] + 1;
    return (short)DAT_0292fc68[0x53] + -1;
  }
  return -1;
}

