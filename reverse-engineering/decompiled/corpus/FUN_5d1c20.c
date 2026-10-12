/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1c20; label: FUN_005d1c20
 */

void FUN_005d1c20(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if (param_1 == (int *)0x0) {
    puVar1 = (undefined4 *)
             FUN_004eef40(0xec,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutexanm.c",0x224);
  }
  else {
    puVar1 = (undefined4 *)(*param_1 + 3U & 0xfffffffc);
    *param_1 = (int)(puVar1 + 0x3b);
  }
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_4;
    puVar1[1] = 0;
    puVar1[0x22] = 0;
    puVar1[0x33] = 0;
    puVar1[0x34] = 0;
    puVar1[0x35] = 0;
    puVar1[0x36] = 0;
    puVar1[0x37] = param_2;
    puVar1[0x38] = param_3;
    puVar1[0x39] = 0;
    if (param_1 != (int *)0x0) {
      puVar1[0x3a] = puVar1[0x3a] & 0xfffffffe;
      return;
    }
    puVar1[0x3a] = puVar1[0x3a] | 1;
  }
  return;
}

