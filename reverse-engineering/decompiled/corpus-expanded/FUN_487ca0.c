/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x487ca0; label: FUN_00487ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00487ca0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 != 0) {
    uVar1 = *(uint *)(param_2 + 0x1fc);
    if (((((uVar1 & 1) != 0) && ((uVar1 & 0x1000) != 0)) && (param_2 != param_1)) &&
       (((*(char *)(param_2 + 0x28b) == '\0' && (-1 < (char)uVar1)) &&
        ((*(byte *)(param_2 + 0x7c5) & 2) == 0)))) {
LAB_00487d23:
      uVar1 = *(uint *)(param_1 + 0x1fc);
      uVar2 = *(uint *)(param_2 + 0x1fc);
      iVar3 = FUN_004876a0(param_1,param_2,0,0,param_3);
      if (iVar3 == 2) {
        *(undefined4 *)(param_1 + 0x7c0) = 0x40400000;
        *(int *)(param_1 + 0x7c8) = param_2;
        *(byte *)(param_1 + 0x7c5) = *(byte *)(param_1 + 0x7c5) & 0xf7 | 4;
        return 0;
      }
      if (iVar3 == 0) {
        return 0;
      }
      *(uint *)(param_2 + 0x1fc) =
           *(uint *)(param_2 + 0x1fc) ^ ((uVar1 >> 7 & 1) << 7 ^ *(uint *)(param_2 + 0x1fc)) & 0x80;
      *(uint *)(param_1 + 0x1fc) =
           *(uint *)(param_1 + 0x1fc) ^ ((uVar2 >> 7 & 1) << 7 ^ *(uint *)(param_1 + 0x1fc)) & 0x80;
      return 1;
    }
  }
  piVar4 = &DAT_0093d7f0;
  do {
    param_2 = *piVar4;
    if (param_2 != 0) {
      uVar1 = *(uint *)(param_2 + 0x1fc);
      if ((((uVar1 & 1) != 0) && ((uVar1 & 0x1000) != 0)) &&
         ((param_2 != param_1 &&
          (((*(char *)(param_2 + 0x28b) == '\0' && (-1 < (char)uVar1)) &&
           ((*(byte *)(param_2 + 0x7c5) & 2) == 0)))))) goto LAB_00487d23;
    }
    piVar4 = piVar4 + 1;
    if (0x93d80f < (int)piVar4) {
      return 0;
    }
  } while( true );
}

