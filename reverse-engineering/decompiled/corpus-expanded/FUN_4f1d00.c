/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1d00; label: FUN_004f1d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004f1d00(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            uint *param_10,uint *param_11)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)(*param_10 + 0xf & 0xfffffff0);
  *param_10 = (uint)puVar1;
  if ((uint)((int)puVar1 + param_2 + (param_1 * 3 + 0x12) * 4) <= *param_11) {
    *param_10 = (uint)(puVar1 + 0xe);
    puVar1[1] = param_6;
    *puVar1 = 0;
    puVar1[3] = param_7;
    puVar1[6] = 0;
    puVar1[9] = 0;
    puVar1[2] = param_8;
    puVar1[0xb] = param_3;
    puVar1[4] = param_9;
    puVar1[0xd] = param_4;
    puVar1[7] = param_1;
    puVar1[10] = param_2;
    puVar1[0xc] = param_5;
    puVar1[5] = *param_10;
    uVar2 = *param_10 + 0xf + param_1 * 0xc & 0xfffffff0;
    *param_10 = uVar2;
    puVar1[8] = uVar2;
    *param_10 = *param_10 + param_2;
  }
  return 0;
}

