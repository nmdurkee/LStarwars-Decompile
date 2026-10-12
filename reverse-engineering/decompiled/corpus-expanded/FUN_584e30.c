/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x584e30; label: FUN_00584e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00584e30(undefined2 param_1,int param_2,int *param_3)

{
  undefined2 uVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  int unaff_EDI;
  float10 fVar5;
  undefined1 local_c;
  
  if (*(short *)(in_EAX + 8) != -1) {
    puVar4 = (undefined2 *)(*param_3 * 0x34 + param_2);
    *puVar4 = param_1;
    puVar4[1] = 0xffff;
    puVar4[2] = *(undefined2 *)(in_EAX + 8);
    *(undefined4 *)(puVar4 + 4) = 0x3f800000;
    *(undefined4 *)(puVar4 + 10) = 0x8000;
    *(undefined4 *)(puVar4 + 6) = 0x3f800000;
    puVar4[0xc] = 0;
    *(undefined1 *)(puVar4 + 0xd) = 0;
    *(undefined4 *)(puVar4 + 0xe) = 0;
    *(undefined1 *)((int)puVar4 + 0x1b) = 0;
    *(undefined4 *)(puVar4 + 0x10) = 0;
    puVar4[0x14] = 0xffff;
    *(undefined4 *)(puVar4 + 0x12) = 0;
    puVar4[0x15] = 0xffff;
    *(undefined4 *)(puVar4 + 0x16) = 0;
    *(undefined1 *)(puVar4 + 3) = 0;
    *(undefined4 *)(puVar4 + 0x18) = 0;
    *(undefined1 *)((int)puVar4 + 7) = 0;
    iVar2 = FUN_004fc5b0();
    if (iVar2 != 0) {
      do {
        iVar2 = FUN_004f7fb0();
        if (iVar2 != 0) {
          iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"deb_name");
          if (iVar2 == 0) {
            iVar2 = FUN_004f7fb0();
            if (iVar2 != 0) {
              if (DAT_0093b0dc == 0) {
                puVar4[1] = 0xffff;
              }
              else {
                uVar1 = FUN_0062c3b0(DAT_0093b0dc,*(undefined4 *)(unaff_EDI + 0x510));
                puVar4[1] = uVar1;
              }
            }
          }
          else {
            iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"condition");
            if (iVar2 == 0) {
              iVar2 = FUN_004f7fb0();
              if (iVar2 != 0) {
                iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"on_ground");
                if (iVar2 == 0) {
                  *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x10;
                }
                else {
                  iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"under_water");
                  if (iVar2 == 0) {
                    *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x20;
                  }
                  else {
                    iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"above_water");
                    if (iVar2 == 0) {
                      *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x40;
                    }
                    else {
                      iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"intersect_water");
                      if (iVar2 == 0) {
                        *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x80;
                      }
                    }
                  }
                }
              }
            }
            else {
              iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"in_only");
              if (iVar2 == 0) {
                *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x100;
              }
              else {
                iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"not_in");
                if (iVar2 == 0) {
                  *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x200;
                }
                else {
                  iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"player_only");
                  if (iVar2 == 0) {
                    *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x400;
                  }
                  else {
                    iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"num_particles");
                    if (iVar2 == 0) {
                      iVar2 = FUN_004f9e70();
                      if (0 < iVar2) {
                        *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 1;
                        *(char *)((int)puVar4 + 0x1b) = (char)iVar2;
                      }
                    }
                    else {
                      iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"frame");
                      if ((iVar2 == 0) ||
                         (iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"frame1"),
                         iVar2 == 0)) {
                        fVar5 = (float10)FUN_004f8100();
                        *(float *)(puVar4 + 4) = (float)fVar5;
                      }
                      else {
                        iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"frame2");
                        if (iVar2 == 0) {
                          fVar5 = (float10)FUN_004f8100();
                          *(float *)(puVar4 + 6) = (float)fVar5;
                        }
                        else {
                          iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"random");
                          if (iVar2 == 0) {
                            fVar5 = (float10)FUN_004f8100();
                            local_c = (undefined1)(int)ROUND(fVar5 * (float10)255.0);
                            *(undefined1 *)(puVar4 + 0xd) = local_c;
                          }
                          else {
                            iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"rumble");
                            if (iVar2 == 0) {
                              fVar5 = (float10)FUN_004f8100();
                              *(float *)(puVar4 + 0xe) = ABS((float)fVar5);
                            }
                            else {
                              iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),&DAT_0076343c)
                              ;
                              if (iVar2 == 0) {
                                fVar5 = (float10)FUN_004f8100();
                                *(float *)(puVar4 + 0x10) = ABS((float)fVar5);
                              }
                              else {
                                iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"judder");
                                if (iVar2 == 0) {
                                  fVar5 = (float10)FUN_004f8100();
                                  *(float *)(puVar4 + 0x12) = (float)fVar5;
                                }
                                else {
                                  iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),"timing");
                                  if (iVar2 == 0) {
                                    iVar2 = FUN_004f7fb0();
                                    if (iVar2 != 0) {
                                      iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),
                                                           "constant");
                                      if (iVar2 == 0) {
                                        *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 4;
                                      }
                                      else {
                                        iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),
                                                             "between");
                                        if (iVar2 == 0) {
                                          *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 8;
                                        }
                                      }
                                    }
                                  }
                                  else {
                                    iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),
                                                         "particles_per_frame");
                                    if (iVar2 == 0) {
                                      fVar5 = (float10)FUN_004f8100();
                                      *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 1;
                                      *(float *)(puVar4 + 8) = ABS((float)fVar5);
                                    }
                                    else {
                                      iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),
                                                           "particles_per_second");
                                      if (iVar2 == 0) {
                                        fVar5 = (float10)FUN_004f8100();
                                        *(uint *)(puVar4 + 10) = *(uint *)(puVar4 + 10) | 0x800001;
                                        *(float *)(puVar4 + 8) = ABS((float)fVar5);
                                      }
                                      else {
                                        iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),
                                                             "locators");
                                        if (iVar2 == 0) {
                                          iVar2 = FUN_004f7fb0();
                                          while (iVar2 != 0) {
                                            uVar3 = FUN_004f29a0(*(undefined4 *)(unaff_EDI + 0x510))
                                            ;
                                            if (uVar3 < 0x10) {
                                              puVar4[0xc] = puVar4[0xc] |
                                                            (ushort)(1 << ((byte)uVar3 & 0x1f));
                                            }
                                            iVar2 = FUN_004f7fb0();
                                          }
                                        }
                                        else {
                                          iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),
                                                               &DAT_007623ec);
                                          if (iVar2 == 0) {
                                            iVar2 = FUN_004f7fb0();
                                            if (iVar2 != 0) {
                                              uVar1 = FUN_00650dc0(*(undefined4 *)
                                                                    (unaff_EDI + 0x510));
                                              puVar4[0x14] = uVar1;
                                            }
                                          }
                                          else {
                                            iVar2 = FUN_004f8b10(*(undefined4 *)(unaff_EDI + 0x510),
                                                                 "sfx_2d");
                                            if (iVar2 == 0) {
                                              *(uint *)(puVar4 + 10) =
                                                   *(uint *)(puVar4 + 10) & 0xffff7fff;
                                            }
                                            else {
                                              iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                    (unaff_EDI + 0x510),"volume");
                                              if (iVar2 == 0) {
                                                fVar5 = (float10)FUN_004f8100();
                                                *(uint *)(puVar4 + 10) =
                                                     *(uint *)(puVar4 + 10) | 0x10000;
                                                *(float *)(puVar4 + 0x16) = ABS((float)fVar5);
                                              }
                                              else {
                                                iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                      (unaff_EDI + 0x510),"surfaces"
                                                                    );
                                                if (iVar2 == 0) {
                                                  iVar2 = FUN_004f7fb0();
                                                  if ((iVar2 != 0) &&
                                                     (iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                            (unaff_EDI + 0x510),
                                                                           "non_solid"), iVar2 == 0)
                                                     ) {
                                                    puVar4[0x15] = ~DAT_00951004;
                                                  }
                                                }
                                                else {
                                                  iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                        (unaff_EDI + 0x510),
                                                                       "at_ter_surface");
                                                  if (iVar2 == 0) {
                                                    *(uint *)(puVar4 + 10) =
                                                         *(uint *)(puVar4 + 10) | 0x2000;
                                                  }
                                                  else {
                                                    iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                          (unaff_EDI + 0x510),
                                                                         "at_obj_bottom");
                                                    if (iVar2 == 0) {
                                                      *(uint *)(puVar4 + 10) =
                                                           *(uint *)(puVar4 + 10) | 0x1000;
                                                    }
                                                    else {
                                                      iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                            (unaff_EDI + 0x510),
                                                                           "at_locator_average");
                                                      if (iVar2 == 0) {
                                                        *(uint *)(puVar4 + 10) =
                                                             *(uint *)(puVar4 + 10) | 0x800;
                                                      }
                                                      else {
                                                        iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                              (unaff_EDI + 0x510),
                                                                             "at_ter_layer");
                                                        if (iVar2 == 0) {
                                                          *(uint *)(puVar4 + 10) =
                                                               *(uint *)(puVar4 + 10) | 0x4000;
                                                        }
                                                        else {
                                                          iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                                (unaff_EDI + 0x510),
                                                                               "min_mode");
                                                          if (iVar2 == 0) {
                                                            iVar2 = FUN_004f7fb0();
                                                            if (iVar2 != 0) {
                                                              iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                                    (unaff_EDI +
                                                                                    0x510),
                                                  "xz_speed");
                                                  if (iVar2 == 0) {
                                                    *(uint *)(puVar4 + 10) =
                                                         *(uint *)(puVar4 + 10) | 0x40000;
                                                  }
                                                  else {
                                                    iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                          (unaff_EDI + 0x510),
                                                                         "xyz_speed");
                                                    if (iVar2 == 0) {
                                                      *(uint *)(puVar4 + 10) =
                                                           *(uint *)(puVar4 + 10) | 0x100000;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                          (unaff_EDI + 0x510),
                                                                         "max_mode");
                                                    if (iVar2 == 0) {
                                                      iVar2 = FUN_004f7fb0();
                                                      if (iVar2 != 0) {
                                                        iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                              (unaff_EDI + 0x510),
                                                                             "xz_speed");
                                                        if (iVar2 == 0) {
                                                          *(uint *)(puVar4 + 10) =
                                                               *(uint *)(puVar4 + 10) | 0x80000;
                                                        }
                                                        else {
                                                          iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                                (unaff_EDI + 0x510),
                                                                               "xyz_speed");
                                                          if (iVar2 == 0) {
                                                            *(uint *)(puVar4 + 10) =
                                                                 *(uint *)(puVar4 + 10) | 0x200000;
                                                          }
                                                        }
                                                      }
                                                    }
                                                    else {
                                                      iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                            (unaff_EDI + 0x510),
                                                                           "min_val");
                                                      if (iVar2 == 0) {
                                                        fVar5 = (float10)FUN_004f8100();
                                                        *(float *)(puVar4 + 0x16) = (float)fVar5;
                                                      }
                                                      else {
                                                        iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                              (unaff_EDI + 0x510),
                                                                             "max_val");
                                                        if (iVar2 == 0) {
                                                          fVar5 = (float10)FUN_004f8100();
                                                          *(float *)(puVar4 + 0x18) = (float)fVar5;
                                                        }
                                                        else {
                                                          iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                                (unaff_EDI + 0x510),
                                                                               "at_obj_speed");
                                                          if (iVar2 == 0) {
                                                            *(uint *)(puVar4 + 10) =
                                                                 *(uint *)(puVar4 + 10) | 0x400000;
                                                          }
                                                          else {
                                                            iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                                  (unaff_EDI + 0x510
                                                                                  ),"left_footprint"
                                                                                );
                                                            if (iVar2 == 0) {
                                                              *(uint *)(puVar4 + 10) =
                                                                   *(uint *)(puVar4 + 10) |
                                                                   0x1000000;
                                                            }
                                                            else {
                                                              iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                                    (unaff_EDI +
                                                                                    0x510),
                                                  "right_footprint");
                                                  if (iVar2 == 0) {
                                                    *(uint *)(puVar4 + 10) =
                                                         *(uint *)(puVar4 + 10) | 0x2000000;
                                                  }
                                                  else {
                                                    iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                          (unaff_EDI + 0x510),
                                                                         "use_locator_matrix");
                                                    if (iVar2 == 0) {
                                                      *(uint *)(puVar4 + 10) =
                                                           *(uint *)(puVar4 + 10) | 0x4000000;
                                                    }
                                                    else {
                                                      iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                            (unaff_EDI + 0x510),
                                                                           "bits_on");
                                                      if (iVar2 == 0) {
                                                        iVar2 = FUN_004f7fb0();
                                                        while (iVar2 != 0) {
                                                          uVar3 = FUN_004f29a0(*(undefined4 *)
                                                                                (unaff_EDI + 0x510))
                                                          ;
                                                          if (uVar3 < 8) {
                                                            *(byte *)(puVar4 + 3) =
                                                                 *(byte *)(puVar4 + 3) |
                                                                 '\x01' << ((byte)uVar3 & 0x1f);
                                                          }
                                                          iVar2 = FUN_004f7fb0();
                                                        }
                                                      }
                                                      else {
                                                        iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                              (unaff_EDI + 0x510),
                                                                             "bits_off");
                                                        if (iVar2 == 0) {
                                                          iVar2 = FUN_004f7fb0();
                                                          while (iVar2 != 0) {
                                                            uVar3 = FUN_004f29a0(*(undefined4 *)
                                                                                  (unaff_EDI + 0x510
                                                                                  ));
                                                            if (uVar3 < 8) {
                                                              *(byte *)((int)puVar4 + 7) =
                                                                   *(byte *)((int)puVar4 + 7) |
                                                                   '\x01' << ((byte)uVar3 & 0x1f);
                                                            }
                                                            iVar2 = FUN_004f7fb0();
                                                          }
                                                        }
                                                        else {
                                                          iVar2 = FUN_004f8b10(*(undefined4 *)
                                                                                (unaff_EDI + 0x510),
                                                                               "effect_end");
                                                          if (iVar2 == 0) {
                                                            *param_3 = *param_3 + 1;
                                                            return;
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        iVar2 = FUN_004fc5b0();
      } while (iVar2 != 0);
      return;
    }
  }
  return;
}

