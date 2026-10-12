/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c5330; label: FUN_005c5330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c5330(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *in_ECX;
  
  if ((uint)in_ECX[3] < (uint)in_ECX[2]) {
    *(undefined1 *)(in_ECX + 4) = 0;
    uVar1 = param_1[1];
    uVar2 = param_1[2];
    puVar3 = (undefined4 *)(in_ECX[3] * 0xa0 + *in_ECX);
    *puVar3 = *param_1;
    puVar3[1] = uVar1;
    puVar3[2] = uVar2;
    puVar3[3] = 0x3f800000;
    puVar3 = (undefined4 *)(in_ECX[3] * 0xa0 + 0x10 + *in_ECX);
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    *puVar3 = *param_2;
    puVar3[1] = uVar1;
    puVar3[2] = uVar2;
    puVar3[3] = 0x3f800000;
    puVar3 = (undefined4 *)(in_ECX[3] * 0xa0 + 0x20 + *in_ECX);
    uVar1 = param_3[1];
    uVar2 = param_3[2];
    *puVar3 = *param_3;
    puVar3[1] = uVar1;
    puVar3[2] = uVar2;
    puVar3[3] = 0x3f800000;
    puVar3 = (undefined4 *)(in_ECX[3] * 0xa0 + 0x30 + *in_ECX);
    uVar1 = param_4[1];
    uVar2 = param_4[2];
    *puVar3 = *param_4;
    puVar3[1] = uVar1;
    puVar3[2] = uVar2;
    puVar3[3] = 0x3f800000;
    in_ECX[3] = in_ECX[3] + 1;
  }
  return;
}

