/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d35e0; label: FUN_005d35e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 *
FUN_005d35e0(int *param_1,undefined4 param_2,undefined4 param_3,void *param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == (int *)0x0) {
    puVar2 = (undefined4 *)
             FUN_004eef40(param_5 * 2 + 0x20,
                          "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nutexanm.c",0x6b8);
  }
  else {
    puVar2 = (undefined4 *)(*param_1 + 3U & 0xfffffffc);
    *param_1 = (int)puVar2 + param_5 * 2 + 0x20;
  }
  puVar2[1] = 0;
  *puVar2 = 0;
  puVar2[2] = puVar2 + 8;
  *(short *)(puVar2 + 3) = (short)param_5;
  puVar2[4] = param_3;
  puVar2[6] = 0;
  _memcpy(puVar2 + 8,param_4,param_5 * 2);
  uVar1 = FUN_005d1c20(param_1,param_3,puVar2[2],param_2);
  puVar2[5] = uVar1;
  return puVar2;
}

