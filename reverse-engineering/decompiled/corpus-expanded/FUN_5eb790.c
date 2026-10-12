/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5eb790; label: FUN_005eb790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005eb790(int param_1,undefined4 param_2,float param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  short local_c;
  uint local_8;
  undefined4 local_4;
  
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_c = *(short *)(DAT_00973880 + 4);
  local_10 = 0;
  iVar1 = FUN_006de8d0((local_c + 1) * 0x30);
  local_8 = iVar1 + 0xfU & 0xfffffff0;
  local_4 = FUN_006de8d0((int)local_c);
  local_10 = *(undefined4 *)(param_1 + 0x168);
  FUN_005cc0d0(param_2,param_3 - 1.0,&local_10,local_10,0);
  if ((param_4 != 0) && (DAT_00973884 != (code *)0x0)) {
    (*DAT_00973884)(&local_10,param_1,param_4,param_5);
  }
  FUN_005e9d90(&local_10,param_1,param_6,param_2,param_7,&local_1c,param_8);
  FUN_006de960();
  FUN_006de960();
  return;
}

