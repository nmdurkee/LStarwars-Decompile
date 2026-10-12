/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e5a30; label: FUN_006e5a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5a30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14)

{
  _DAT_0297bea0 =
       D3DXCreateTextureFromFileInMemoryEx
                 (DAT_029765cc,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                  param_9,param_10,param_11,param_12,param_13,param_14);
  return;
}

