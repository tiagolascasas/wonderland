; ModuleID = 'C:/Users/Tiago/Dev/Experiments/kNNChunkInstantiation/knn_vitis/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: inaccessiblememonly nounwind
declare void @llvm.sideeffect() #0

; Function Attrs: noinline
define void @apatb_kNN_PredictAll_ir([43 x double]* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4336" %training_X, i8* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4336" %training_Y, [43 x double]* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="1082" %testing_X, i8* noalias nocapture nonnull "fpga.decayed.dim.hint"="1082" %testing_Y, double* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="43" %min, double* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="43" %max) local_unnamed_addr #1 {
entry:
  %malloccall_0 = call i8* @malloc(i64 248712)
  %malloccall_1 = call i8* @malloc(i64 248712)
  %malloccall_2 = call i8* @malloc(i64 248712)
  %malloccall_3 = call i8* @malloc(i64 248712)
  %malloccall_4 = call i8* @malloc(i64 248712)
  %malloccall_5 = call i8* @malloc(i64 248712)
  %training_X_copy_0 = bitcast i8* %malloccall_0 to [723 x [43 x double]]*
  %training_X_copy_1 = bitcast i8* %malloccall_1 to [723 x [43 x double]]*
  %training_X_copy_2 = bitcast i8* %malloccall_2 to [723 x [43 x double]]*
  %training_X_copy_3 = bitcast i8* %malloccall_3 to [723 x [43 x double]]*
  %training_X_copy_4 = bitcast i8* %malloccall_4 to [723 x [43 x double]]*
  %training_X_copy_5 = bitcast i8* %malloccall_5 to [723 x [43 x double]]*
  %malloccall1 = tail call i8* @malloc(i64 4336)
  %training_Y_copy = bitcast i8* %malloccall1 to [4336 x i8]*
  %malloccall2 = tail call i8* @malloc(i64 372208)
  %testing_X_copy = bitcast i8* %malloccall2 to [1082 x [43 x double]]*
  %testing_Y_copy = alloca [1082 x i8], align 512
  %min_copy = alloca [43 x double], align 512
  %max_copy = alloca [43 x double], align 512
  %0 = bitcast [43 x double]* %training_X to [4336 x [43 x double]]*
  %1 = bitcast i8* %training_Y to [4336 x i8]*
  %2 = bitcast [43 x double]* %testing_X to [1082 x [43 x double]]*
  %3 = bitcast i8* %testing_Y to [1082 x i8]*
  %4 = bitcast double* %min to [43 x double]*
  %5 = bitcast double* %max to [43 x double]*
  call void @copy_in([4336 x [43 x double]]* nonnull %0, [723 x [43 x double]]* %training_X_copy_0, [723 x [43 x double]]* %training_X_copy_1, [723 x [43 x double]]* %training_X_copy_2, [723 x [43 x double]]* %training_X_copy_3, [723 x [43 x double]]* %training_X_copy_4, [723 x [43 x double]]* %training_X_copy_5, [4336 x i8]* nonnull %1, [4336 x i8]* %training_Y_copy, [1082 x [43 x double]]* nonnull %2, [1082 x [43 x double]]* %testing_X_copy, [1082 x i8]* nonnull %3, [1082 x i8]* nonnull align 512 %testing_Y_copy, [43 x double]* nonnull %4, [43 x double]* nonnull align 512 %min_copy, [43 x double]* nonnull %5, [43 x double]* nonnull align 512 %max_copy)
  %_0 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %training_X_copy_0, i32 0, i32 0
  %_1 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %training_X_copy_1, i32 0, i32 0
  %_2 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %training_X_copy_2, i32 0, i32 0
  %_3 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %training_X_copy_3, i32 0, i32 0
  %_4 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %training_X_copy_4, i32 0, i32 0
  %_5 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %training_X_copy_5, i32 0, i32 0
  %6 = getelementptr inbounds [1082 x [43 x double]], [1082 x [43 x double]]* %testing_X_copy, i32 0, i32 0
  %7 = getelementptr inbounds [1082 x i8], [1082 x i8]* %testing_Y_copy, i32 0, i32 0
  %8 = getelementptr inbounds [43 x double], [43 x double]* %min_copy, i32 0, i32 0
  %9 = getelementptr inbounds [43 x double], [43 x double]* %max_copy, i32 0, i32 0
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x double]* %_0, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x double]* %_1, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x double]* %_2, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x double]* %_3, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x double]* %_4, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x double]* %_5, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @apatb_kNN_PredictAll_hw([723 x [43 x double]]* %training_X_copy_0, [723 x [43 x double]]* %training_X_copy_1, [723 x [43 x double]]* %training_X_copy_2, [723 x [43 x double]]* %training_X_copy_3, [723 x [43 x double]]* %training_X_copy_4, [723 x [43 x double]]* %training_X_copy_5, i8* %malloccall1, [43 x double]* %6, i8* %7, double* %8, double* %9)
  call void @copy_back([4336 x [43 x double]]* %0, [723 x [43 x double]]* %training_X_copy_0, [723 x [43 x double]]* %training_X_copy_1, [723 x [43 x double]]* %training_X_copy_2, [723 x [43 x double]]* %training_X_copy_3, [723 x [43 x double]]* %training_X_copy_4, [723 x [43 x double]]* %training_X_copy_5, [4336 x i8]* %1, [4336 x i8]* %training_Y_copy, [1082 x [43 x double]]* %2, [1082 x [43 x double]]* %testing_X_copy, [1082 x i8]* %3, [1082 x i8]* %testing_Y_copy, [43 x double]* %4, [43 x double]* %min_copy, [43 x double]* %5, [43 x double]* %max_copy)
  call void @free(i8* %malloccall_0)
  call void @free(i8* %malloccall_1)
  call void @free(i8* %malloccall_2)
  call void @free(i8* %malloccall_3)
  call void @free(i8* %malloccall_4)
  call void @free(i8* %malloccall_5)
  tail call void @free(i8* %malloccall1)
  tail call void @free(i8* %malloccall2)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a4336i8([4336 x i8]* noalias, [4336 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [4336 x i8]* %0, null
  %3 = icmp eq [4336 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [4336 x i8], [4336 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [4336 x i8], [4336 x i8]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i8, i8* %src.addr, align 1
  store i8 %5, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 4336
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a1082a43f64([1082 x [43 x double]]* noalias, [1082 x [43 x double]]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [1082 x [43 x double]]* %0, null
  %3 = icmp eq [1082 x [43 x double]]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  br label %for.loop2

for.loop2:                                        ; preds = %for.loop2, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %for.loop2 ]
  %dst.addr57 = getelementptr [1082 x [43 x double]], [1082 x [43 x double]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %src.addr68 = getelementptr [1082 x [43 x double]], [1082 x [43 x double]]* %1, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %5 = load double, double* %src.addr68, align 8
  store double %5, double* %dst.addr57, align 8
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 43
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %for.loop2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 1082
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* noalias align 512, [1082 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [1082 x i8]* %0, null
  %3 = icmp eq [1082 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [1082 x i8], [1082 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [1082 x i8], [1082 x i8]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i8, i8* %src.addr, align 1
  store i8 %5, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 1082
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a43f64([43 x double]* noalias align 512, [43 x double]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [43 x double]* %0, null
  %3 = icmp eq [43 x double]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [43 x double], [43 x double]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [43 x double], [43 x double]* %1, i64 0, i64 %for.loop.idx1
  %5 = load double, double* %src.addr, align 8
  store double %5, double* %dst.addr, align 8
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 43
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

declare void @free(i8*) local_unnamed_addr

; Function Attrs: nounwind
declare void @llvm.assume(i1) #3

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a4336a43f64.77.78([723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_4, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_5, [4336 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1") #2 {
entry:
  %1 = icmp eq [723 x [43 x double]]* %_0, null
  %2 = icmp eq [4336 x [43 x double]]* %0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %4 = urem i64 %for.loop.idx10, 6
  %5 = udiv i64 %for.loop.idx10, 6
  %6 = trunc i64 %4 to i3
  %7 = icmp eq i3 %6, -3
  br label %for.loop2

for.loop2:                                        ; preds = %dst.addr57.exit, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %dst.addr57.exit ]
  %dst.addr57_0 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_0, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_1 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_1, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_2 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_2, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_3 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_3, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_4 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_4, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_5 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_5, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68 = getelementptr [4336 x [43 x double]], [4336 x [43 x double]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %8 = load double, double* %src.addr68, align 8
  switch i3 %6, label %dst.addr57.case.5 [
    i3 0, label %dst.addr57.case.0
    i3 1, label %dst.addr57.case.1
    i3 2, label %dst.addr57.case.2
    i3 3, label %dst.addr57.case.3
    i3 -4, label %dst.addr57.case.4
  ]

dst.addr57.case.0:                                ; preds = %for.loop2
  store double %8, double* %dst.addr57_0, align 8
  br label %dst.addr57.exit

dst.addr57.case.1:                                ; preds = %for.loop2
  store double %8, double* %dst.addr57_1, align 8
  br label %dst.addr57.exit

dst.addr57.case.2:                                ; preds = %for.loop2
  store double %8, double* %dst.addr57_2, align 8
  br label %dst.addr57.exit

dst.addr57.case.3:                                ; preds = %for.loop2
  store double %8, double* %dst.addr57_3, align 8
  br label %dst.addr57.exit

dst.addr57.case.4:                                ; preds = %for.loop2
  store double %8, double* %dst.addr57_4, align 8
  br label %dst.addr57.exit

dst.addr57.case.5:                                ; preds = %for.loop2
  call void @llvm.assume(i1 %7)
  store double %8, double* %dst.addr57_5, align 8
  br label %dst.addr57.exit

dst.addr57.exit:                                  ; preds = %dst.addr57.case.5, %dst.addr57.case.4, %dst.addr57.case.3, %dst.addr57.case.2, %dst.addr57.case.1, %dst.addr57.case.0
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 43
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %dst.addr57.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 4336
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_in([4336 x [43 x double]]* noalias readonly "orig.arg.no"="0", [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [723 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, [4336 x i8]* noalias readonly "orig.arg.no"="2", [4336 x i8]* noalias "orig.arg.no"="3", [1082 x [43 x double]]* noalias readonly "orig.arg.no"="4", [1082 x [43 x double]]* noalias "orig.arg.no"="5", [1082 x i8]* noalias readonly "orig.arg.no"="6", [1082 x i8]* noalias align 512 "orig.arg.no"="7", [43 x double]* noalias readonly "orig.arg.no"="8", [43 x double]* noalias align 512 "orig.arg.no"="9", [43 x double]* noalias readonly "orig.arg.no"="10", [43 x double]* noalias align 512 "orig.arg.no"="11") #4 {
entry:
  call void @onebyonecpy_hls.p0a4336a43f64.77.78([723 x [43 x double]]* %_0, [723 x [43 x double]]* %_1, [723 x [43 x double]]* %_2, [723 x [43 x double]]* %_3, [723 x [43 x double]]* %_4, [723 x [43 x double]]* %_5, [4336 x [43 x double]]* %0)
  call fastcc void @onebyonecpy_hls.p0a4336i8([4336 x i8]* %2, [4336 x i8]* %1)
  call fastcc void @onebyonecpy_hls.p0a1082a43f64([1082 x [43 x double]]* %4, [1082 x [43 x double]]* %3)
  call fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* align 512 %6, [1082 x i8]* %5)
  call fastcc void @onebyonecpy_hls.p0a43f64([43 x double]* align 512 %8, [43 x double]* %7)
  call fastcc void @onebyonecpy_hls.p0a43f64([43 x double]* align 512 %10, [43 x double]* %9)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a4336a43f64.85.86([4336 x [43 x double]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0", [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5) #2 {
entry:
  %1 = icmp eq [4336 x [43 x double]]* %0, null
  %2 = icmp eq [723 x [43 x double]]* %_0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %4 = urem i64 %for.loop.idx10, 6
  %5 = udiv i64 %for.loop.idx10, 6
  %6 = trunc i64 %4 to i3
  %7 = icmp eq i3 %6, -3
  br label %for.loop2

for.loop2:                                        ; preds = %src.addr68.exit, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %src.addr68.exit ]
  %dst.addr57 = getelementptr [4336 x [43 x double]], [4336 x [43 x double]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %src.addr68_0 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_0, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_1 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_1, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_2 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_2, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_3 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_3, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_4 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_4, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_5 = getelementptr [723 x [43 x double]], [723 x [43 x double]]* %_5, i64 0, i64 %5, i64 %for.loop.idx39
  switch i3 %6, label %src.addr68.case.5 [
    i3 0, label %src.addr68.case.0
    i3 1, label %src.addr68.case.1
    i3 2, label %src.addr68.case.2
    i3 3, label %src.addr68.case.3
    i3 -4, label %src.addr68.case.4
  ]

src.addr68.case.0:                                ; preds = %for.loop2
  %_01 = load double, double* %src.addr68_0, align 8
  br label %src.addr68.exit

src.addr68.case.1:                                ; preds = %for.loop2
  %_12 = load double, double* %src.addr68_1, align 8
  br label %src.addr68.exit

src.addr68.case.2:                                ; preds = %for.loop2
  %_23 = load double, double* %src.addr68_2, align 8
  br label %src.addr68.exit

src.addr68.case.3:                                ; preds = %for.loop2
  %_34 = load double, double* %src.addr68_3, align 8
  br label %src.addr68.exit

src.addr68.case.4:                                ; preds = %for.loop2
  %_45 = load double, double* %src.addr68_4, align 8
  br label %src.addr68.exit

src.addr68.case.5:                                ; preds = %for.loop2
  call void @llvm.assume(i1 %7)
  %_56 = load double, double* %src.addr68_5, align 8
  br label %src.addr68.exit

src.addr68.exit:                                  ; preds = %src.addr68.case.5, %src.addr68.case.4, %src.addr68.case.3, %src.addr68.case.2, %src.addr68.case.1, %src.addr68.case.0
  %8 = phi double [ %_01, %src.addr68.case.0 ], [ %_12, %src.addr68.case.1 ], [ %_23, %src.addr68.case.2 ], [ %_34, %src.addr68.case.3 ], [ %_45, %src.addr68.case.4 ], [ %_56, %src.addr68.case.5 ]
  store double %8, double* %dst.addr57, align 8
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 43
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %src.addr68.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 4336
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_out([4336 x [43 x double]]* noalias "orig.arg.no"="0", [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, [4336 x i8]* noalias "orig.arg.no"="2", [4336 x i8]* noalias readonly "orig.arg.no"="3", [1082 x [43 x double]]* noalias "orig.arg.no"="4", [1082 x [43 x double]]* noalias readonly "orig.arg.no"="5", [1082 x i8]* noalias "orig.arg.no"="6", [1082 x i8]* noalias readonly align 512 "orig.arg.no"="7", [43 x double]* noalias "orig.arg.no"="8", [43 x double]* noalias readonly align 512 "orig.arg.no"="9", [43 x double]* noalias "orig.arg.no"="10", [43 x double]* noalias readonly align 512 "orig.arg.no"="11") #5 {
entry:
  call void @onebyonecpy_hls.p0a4336a43f64.85.86([4336 x [43 x double]]* %0, [723 x [43 x double]]* %_0, [723 x [43 x double]]* %_1, [723 x [43 x double]]* %_2, [723 x [43 x double]]* %_3, [723 x [43 x double]]* %_4, [723 x [43 x double]]* %_5)
  call fastcc void @onebyonecpy_hls.p0a4336i8([4336 x i8]* %1, [4336 x i8]* %2)
  call fastcc void @onebyonecpy_hls.p0a1082a43f64([1082 x [43 x double]]* %3, [1082 x [43 x double]]* %4)
  call fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* %5, [1082 x i8]* align 512 %6)
  call fastcc void @onebyonecpy_hls.p0a43f64([43 x double]* %7, [43 x double]* align 512 %8)
  call fastcc void @onebyonecpy_hls.p0a43f64([43 x double]* %9, [43 x double]* align 512 %10)
  ret void
}

declare void @apatb_kNN_PredictAll_hw([723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, i8*, [43 x double]*, i8*, double*, double*)

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_back([4336 x [43 x double]]* noalias "orig.arg.no"="0", [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_4, [723 x [43 x double]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_5, [4336 x i8]* noalias "orig.arg.no"="2", [4336 x i8]* noalias readonly "orig.arg.no"="3", [1082 x [43 x double]]* noalias "orig.arg.no"="4", [1082 x [43 x double]]* noalias readonly "orig.arg.no"="5", [1082 x i8]* noalias "orig.arg.no"="6", [1082 x i8]* noalias readonly align 512 "orig.arg.no"="7", [43 x double]* noalias "orig.arg.no"="8", [43 x double]* noalias readonly align 512 "orig.arg.no"="9", [43 x double]* noalias "orig.arg.no"="10", [43 x double]* noalias readonly align 512 "orig.arg.no"="11") #5 {
entry:
  call fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* %5, [1082 x i8]* align 512 %6)
  ret void
}

define void @kNN_PredictAll_hw_stub_wrapper([723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, [723 x [43 x double]]*, i8*, [43 x double]*, i8*, double*, double*) #6 {
entry:
  %malloccall = tail call i8* @malloc(i64 1491584)
  %11 = bitcast i8* %malloccall to [4336 x [43 x double]]*
  %12 = bitcast i8* %6 to [4336 x i8]*
  %13 = bitcast [43 x double]* %7 to [1082 x [43 x double]]*
  %14 = bitcast i8* %8 to [1082 x i8]*
  %15 = bitcast double* %9 to [43 x double]*
  %16 = bitcast double* %10 to [43 x double]*
  call void @copy_out([4336 x [43 x double]]* %11, [723 x [43 x double]]* %0, [723 x [43 x double]]* %1, [723 x [43 x double]]* %2, [723 x [43 x double]]* %3, [723 x [43 x double]]* %4, [723 x [43 x double]]* %5, [4336 x i8]* null, [4336 x i8]* %12, [1082 x [43 x double]]* null, [1082 x [43 x double]]* %13, [1082 x i8]* null, [1082 x i8]* %14, [43 x double]* null, [43 x double]* %15, [43 x double]* null, [43 x double]* %16)
  %17 = bitcast [4336 x [43 x double]]* %11 to [43 x double]*
  %18 = bitcast [4336 x i8]* %12 to i8*
  %19 = bitcast [1082 x [43 x double]]* %13 to [43 x double]*
  %20 = bitcast [1082 x i8]* %14 to i8*
  %21 = bitcast [43 x double]* %15 to double*
  %22 = bitcast [43 x double]* %16 to double*
  call void @kNN_PredictAll_hw_stub([43 x double]* %17, i8* %18, [43 x double]* %19, i8* %20, double* %21, double* %22)
  call void @copy_in([4336 x [43 x double]]* %11, [723 x [43 x double]]* %0, [723 x [43 x double]]* %1, [723 x [43 x double]]* %2, [723 x [43 x double]]* %3, [723 x [43 x double]]* %4, [723 x [43 x double]]* %5, [4336 x i8]* null, [4336 x i8]* %12, [1082 x [43 x double]]* null, [1082 x [43 x double]]* %13, [1082 x i8]* null, [1082 x i8]* %14, [43 x double]* null, [43 x double]* %15, [43 x double]* null, [43 x double]* %16)
  ret void
}

declare void @kNN_PredictAll_hw_stub([43 x double]*, i8*, [43 x double]*, i8*, double*, double*)

attributes #0 = { inaccessiblememonly nounwind }
attributes #1 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { nounwind }
attributes #4 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #5 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #6 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = !DILocation(line: 211, column: 9, scope: !6)
!6 = distinct !DILexicalBlock(scope: !8, file: !7, line: 210, column: 5)
!7 = !DIFile(filename: "knn/knn.cpp", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!8 = distinct !DILexicalBlock(scope: !9, file: !7, line: 209, column: 23)
!9 = distinct !DILexicalBlock(scope: !10, file: !7, line: 209, column: 23)
!10 = distinct !DISubprogram(name: "kNN_PredictAll", linkageName: "_Z14kNN_PredictAllPA43_dPcS0_S1_PdS2_", scope: !7, file: !7, line: 182, type: !11, isLocal: false, isDefinition: true, scopeLine: 187, flags: DIFlagPrototyped, isOptimized: false, unit: !21, variables: !4)
!11 = !DISubroutineType(types: !12)
!12 = !{null, !13, !18, !13, !18, !20, !20}
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !14, size: 64)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !15, size: 2752, elements: !16)
!15 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!16 = !{!17}
!17 = !DISubrange(count: 43)
!18 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !19, size: 64)
!19 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!20 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !15, size: 64)
!21 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus, file: !22, producer: "clang version 7.0.0 ", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !4, retainedTypes: !23, imports: !25)
!22 = !DIFile(filename: "C:/Users/Tiago/Dev/Experiments/kNNChunkInstantiation/knn_vitis/solution1/.autopilot/db\5Cknn.pp.0.cpp", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!23 = !{!24, !19, !15}
!24 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!25 = !{!26, !33, !38, !40, !42, !46, !48, !50, !52, !54, !56, !58, !60, !65, !69, !71, !73, !77, !79, !81, !83, !85, !87, !89, !91, !94, !96, !100, !105, !107, !109, !111, !113, !115, !117, !119, !121, !123, !125, !129, !133, !135, !137, !139, !141, !143, !145, !147, !149, !151, !153, !155, !157, !159, !161, !163, !167, !171, !175, !177, !179, !181, !183, !185, !187, !189, !191, !193, !197, !201, !205, !207, !209, !211, !216, !220, !224, !226, !228, !230, !232, !234, !236, !238, !240, !242, !244, !246, !248, !253, !257, !261, !263, !265, !267, !273, !277, !281, !283, !285, !287, !289, !291, !293, !297, !301, !303, !305, !307, !309, !313, !317, !321, !323, !325, !327, !329, !331, !333, !337, !341, !345, !347, !351, !355, !357, !359, !361, !363, !365, !367, !372, !375, !377, !379, !381, !383, !385, !387, !389, !391, !393, !395, !397, !400, !403, !406, !409, !412, !414, !416, !418, !420, !422, !424, !426, !428, !430}
!26 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !28, file: !32, line: 52)
!27 = !DINamespace(name: "std", scope: null)
!28 = !DISubprogram(name: "abs", scope: !29, file: !29, line: 254, type: !30, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!29 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Cx86_64-w64-mingw32\5Cinclude\5Cmath.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!30 = !DISubroutineType(types: !31)
!31 = !{!24, !24}
!32 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Clib\5Cgcc\5Cx86_64-w64-mingw32\5C8.3.0\5Cinclude\5Cc++\5Cbits/std_abs.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!33 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !34, file: !37, line: 83)
!34 = !DISubprogram(name: "acos", scope: !29, file: !29, line: 190, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!35 = !DISubroutineType(types: !36)
!36 = !{!15, !15}
!37 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Clib\5Cgcc\5Cx86_64-w64-mingw32\5C8.3.0\5Cinclude\5Cc++\5Ccmath", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!38 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !39, file: !37, line: 102)
!39 = !DISubprogram(name: "asin", scope: !29, file: !29, line: 189, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!40 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !41, file: !37, line: 121)
!41 = !DISubprogram(name: "atan", scope: !29, file: !29, line: 191, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!42 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !43, file: !37, line: 140)
!43 = !DISubprogram(name: "atan2", scope: !29, file: !29, line: 192, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!44 = !DISubroutineType(types: !45)
!45 = !{!15, !15, !15}
!46 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !47, file: !37, line: 161)
!47 = !DISubprogram(name: "ceil", scope: !29, file: !29, line: 198, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!48 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !49, file: !37, line: 180)
!49 = !DISubprogram(name: "cos", scope: !29, file: !29, line: 184, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!50 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !51, file: !37, line: 199)
!51 = !DISubprogram(name: "cosh", scope: !29, file: !29, line: 187, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!52 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !53, file: !37, line: 218)
!53 = !DISubprogram(name: "exp", scope: !29, file: !29, line: 193, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!54 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !55, file: !37, line: 237)
!55 = !DISubprogram(name: "fabs", scope: !29, file: !29, line: 204, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!56 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !57, file: !37, line: 256)
!57 = !DISubprogram(name: "floor", scope: !29, file: !29, line: 199, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!58 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !59, file: !37, line: 275)
!59 = !DISubprogram(name: "fmod", scope: !29, file: !29, line: 246, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!60 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !61, file: !37, line: 296)
!61 = !DISubprogram(name: "frexp", scope: !29, file: !29, line: 244, type: !62, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!62 = !DISubroutineType(types: !63)
!63 = !{!15, !15, !64}
!64 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !24, size: 64)
!65 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !66, file: !37, line: 315)
!66 = !DISubprogram(name: "ldexp", scope: !29, file: !29, line: 243, type: !67, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!67 = !DISubroutineType(types: !68)
!68 = !{!15, !15, !24}
!69 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !70, file: !37, line: 334)
!70 = !DISubprogram(name: "log", scope: !29, file: !29, line: 194, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!71 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !72, file: !37, line: 353)
!72 = !DISubprogram(name: "log10", scope: !29, file: !29, line: 195, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!73 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !74, file: !37, line: 372)
!74 = !DISubprogram(name: "modf", scope: !29, file: !29, line: 245, type: !75, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!75 = !DISubroutineType(types: !76)
!76 = !{!15, !15, !20}
!77 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !78, file: !37, line: 384)
!78 = !DISubprogram(name: "pow", scope: !29, file: !29, line: 196, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!79 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !80, file: !37, line: 421)
!80 = !DISubprogram(name: "sin", scope: !29, file: !29, line: 183, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!81 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !82, file: !37, line: 440)
!82 = !DISubprogram(name: "sinh", scope: !29, file: !29, line: 186, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!83 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !84, file: !37, line: 459)
!84 = !DISubprogram(name: "sqrt", scope: !29, file: !29, line: 197, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!85 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !86, file: !37, line: 478)
!86 = !DISubprogram(name: "tan", scope: !29, file: !29, line: 185, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!87 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !88, file: !37, line: 497)
!88 = !DISubprogram(name: "tanh", scope: !29, file: !29, line: 188, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!89 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !90, file: !37, line: 1065)
!90 = !DIDerivedType(tag: DW_TAG_typedef, name: "double_t", file: !29, line: 373, baseType: !15)
!91 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !92, file: !37, line: 1066)
!92 = !DIDerivedType(tag: DW_TAG_typedef, name: "float_t", file: !29, line: 372, baseType: !93)
!93 = !DIBasicType(name: "float", size: 32, encoding: DW_ATE_float)
!94 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !95, file: !37, line: 1069)
!95 = !DISubprogram(name: "acosh", scope: !29, file: !29, line: 705, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!96 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !97, file: !37, line: 1070)
!97 = !DISubprogram(name: "acoshf", scope: !29, file: !29, line: 706, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!98 = !DISubroutineType(types: !99)
!99 = !{!93, !93}
!100 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !101, file: !37, line: 1071)
!101 = !DISubprogram(name: "acoshl", scope: !29, file: !29, line: 707, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!102 = !DISubroutineType(types: !103)
!103 = !{!104, !104}
!104 = !DIBasicType(name: "long double", size: 64, encoding: DW_ATE_float)
!105 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !106, file: !37, line: 1073)
!106 = !DISubprogram(name: "asinh", scope: !29, file: !29, line: 710, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!107 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !108, file: !37, line: 1074)
!108 = !DISubprogram(name: "asinhf", scope: !29, file: !29, line: 711, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!109 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !110, file: !37, line: 1075)
!110 = !DISubprogram(name: "asinhl", scope: !29, file: !29, line: 712, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!111 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !112, file: !37, line: 1077)
!112 = !DISubprogram(name: "atanh", scope: !29, file: !29, line: 715, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!113 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !114, file: !37, line: 1078)
!114 = !DISubprogram(name: "atanhf", scope: !29, file: !29, line: 716, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!115 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !116, file: !37, line: 1079)
!116 = !DISubprogram(name: "atanhl", scope: !29, file: !29, line: 717, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!117 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !118, file: !37, line: 1081)
!118 = !DISubprogram(name: "cbrt", scope: !29, file: !29, line: 877, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!119 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !120, file: !37, line: 1082)
!120 = !DISubprogram(name: "cbrtf", scope: !29, file: !29, line: 878, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!121 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !122, file: !37, line: 1083)
!122 = !DISubprogram(name: "cbrtl", scope: !29, file: !29, line: 879, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!123 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !124, file: !37, line: 1085)
!124 = !DISubprogram(name: "copysign", scope: !29, file: !29, line: 1063, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!125 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !126, file: !37, line: 1086)
!126 = !DISubprogram(name: "copysignf", scope: !29, file: !29, line: 1064, type: !127, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!127 = !DISubroutineType(types: !128)
!128 = !{!93, !93, !93}
!129 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !130, file: !37, line: 1087)
!130 = !DISubprogram(name: "copysignl", scope: !29, file: !29, line: 1065, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!131 = !DISubroutineType(types: !132)
!132 = !{!104, !104, !104}
!133 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !134, file: !37, line: 1089)
!134 = !DISubprogram(name: "erf", scope: !29, file: !29, line: 901, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!135 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !136, file: !37, line: 1090)
!136 = !DISubprogram(name: "erff", scope: !29, file: !29, line: 902, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!137 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !138, file: !37, line: 1091)
!138 = !DISubprogram(name: "erfl", scope: !29, file: !29, line: 903, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!139 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !140, file: !37, line: 1093)
!140 = !DISubprogram(name: "erfc", scope: !29, file: !29, line: 906, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!141 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !142, file: !37, line: 1094)
!142 = !DISubprogram(name: "erfcf", scope: !29, file: !29, line: 907, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!143 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !144, file: !37, line: 1095)
!144 = !DISubprogram(name: "erfcl", scope: !29, file: !29, line: 908, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!145 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !146, file: !37, line: 1097)
!146 = !DISubprogram(name: "exp2", scope: !29, file: !29, line: 728, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!147 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !148, file: !37, line: 1098)
!148 = !DISubprogram(name: "exp2f", scope: !29, file: !29, line: 729, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!149 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !150, file: !37, line: 1099)
!150 = !DISubprogram(name: "exp2l", scope: !29, file: !29, line: 730, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!151 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !152, file: !37, line: 1101)
!152 = !DISubprogram(name: "expm1", scope: !29, file: !29, line: 734, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!153 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !154, file: !37, line: 1102)
!154 = !DISubprogram(name: "expm1f", scope: !29, file: !29, line: 735, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!155 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !156, file: !37, line: 1103)
!156 = !DISubprogram(name: "expm1l", scope: !29, file: !29, line: 736, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!157 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !158, file: !37, line: 1105)
!158 = !DISubprogram(name: "fdim", scope: !29, file: !29, line: 1109, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!159 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !160, file: !37, line: 1106)
!160 = !DISubprogram(name: "fdimf", scope: !29, file: !29, line: 1110, type: !127, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!161 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !162, file: !37, line: 1107)
!162 = !DISubprogram(name: "fdiml", scope: !29, file: !29, line: 1111, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!163 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !164, file: !37, line: 1109)
!164 = !DISubprogram(name: "fma", scope: !29, file: !29, line: 1130, type: !165, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!165 = !DISubroutineType(types: !166)
!166 = !{!15, !15, !15, !15}
!167 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !168, file: !37, line: 1110)
!168 = !DISubprogram(name: "fmaf", scope: !29, file: !29, line: 1131, type: !169, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!169 = !DISubroutineType(types: !170)
!170 = !{!93, !93, !93, !93}
!171 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !172, file: !37, line: 1111)
!172 = !DISubprogram(name: "fmal", scope: !29, file: !29, line: 1132, type: !173, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!173 = !DISubroutineType(types: !174)
!174 = !{!104, !104, !104, !104}
!175 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !176, file: !37, line: 1113)
!176 = !DISubprogram(name: "fmax", scope: !29, file: !29, line: 1119, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!177 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !178, file: !37, line: 1114)
!178 = !DISubprogram(name: "fmaxf", scope: !29, file: !29, line: 1120, type: !127, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!179 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !180, file: !37, line: 1115)
!180 = !DISubprogram(name: "fmaxl", scope: !29, file: !29, line: 1121, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!181 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !182, file: !37, line: 1117)
!182 = !DISubprogram(name: "fmin", scope: !29, file: !29, line: 1124, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!183 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !184, file: !37, line: 1118)
!184 = !DISubprogram(name: "fminf", scope: !29, file: !29, line: 1125, type: !127, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!185 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !186, file: !37, line: 1119)
!186 = !DISubprogram(name: "fminl", scope: !29, file: !29, line: 1126, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!187 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !188, file: !37, line: 1121)
!188 = !DISubprogram(name: "hypot", scope: !29, file: !29, line: 882, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!189 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !190, file: !37, line: 1122)
!190 = !DISubprogram(name: "hypotf", scope: !29, file: !29, line: 883, type: !127, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!191 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !192, file: !37, line: 1123)
!192 = !DISubprogram(name: "hypotl", scope: !29, file: !29, line: 887, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!193 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !194, file: !37, line: 1125)
!194 = !DISubprogram(name: "ilogb", scope: !29, file: !29, line: 748, type: !195, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!195 = !DISubroutineType(types: !196)
!196 = !{!24, !15}
!197 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !198, file: !37, line: 1126)
!198 = !DISubprogram(name: "ilogbf", scope: !29, file: !29, line: 749, type: !199, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!199 = !DISubroutineType(types: !200)
!200 = !{!24, !93}
!201 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !202, file: !37, line: 1127)
!202 = !DISubprogram(name: "ilogbl", scope: !29, file: !29, line: 750, type: !203, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!203 = !DISubroutineType(types: !204)
!204 = !{!24, !104}
!205 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !206, file: !37, line: 1129)
!206 = !DISubprogram(name: "lgamma", scope: !29, file: !29, line: 911, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!207 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !208, file: !37, line: 1130)
!208 = !DISubprogram(name: "lgammaf", scope: !29, file: !29, line: 912, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!209 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !210, file: !37, line: 1131)
!210 = !DISubprogram(name: "lgammal", scope: !29, file: !29, line: 913, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!211 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !212, file: !37, line: 1134)
!212 = !DISubprogram(name: "llrint", scope: !29, file: !29, line: 946, type: !213, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!213 = !DISubroutineType(types: !214)
!214 = !{!215, !15}
!215 = !DIBasicType(name: "long long int", size: 64, encoding: DW_ATE_signed)
!216 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !217, file: !37, line: 1135)
!217 = !DISubprogram(name: "llrintf", scope: !29, file: !29, line: 947, type: !218, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!218 = !DISubroutineType(types: !219)
!219 = !{!215, !93}
!220 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !221, file: !37, line: 1136)
!221 = !DISubprogram(name: "llrintl", scope: !29, file: !29, line: 948, type: !222, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!222 = !DISubroutineType(types: !223)
!223 = !{!215, !104}
!224 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !225, file: !37, line: 1138)
!225 = !DISubprogram(name: "llround", scope: !29, file: !29, line: 1038, type: !213, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!226 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !227, file: !37, line: 1139)
!227 = !DISubprogram(name: "llroundf", scope: !29, file: !29, line: 1039, type: !218, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!228 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !229, file: !37, line: 1140)
!229 = !DISubprogram(name: "llroundl", scope: !29, file: !29, line: 1040, type: !222, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!230 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !231, file: !37, line: 1143)
!231 = !DISubprogram(name: "log1p", scope: !29, file: !29, line: 768, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!232 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !233, file: !37, line: 1144)
!233 = !DISubprogram(name: "log1pf", scope: !29, file: !29, line: 769, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!234 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !235, file: !37, line: 1145)
!235 = !DISubprogram(name: "log1pl", scope: !29, file: !29, line: 770, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!236 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !237, file: !37, line: 1147)
!237 = !DISubprogram(name: "log2", scope: !29, file: !29, line: 773, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!238 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !239, file: !37, line: 1148)
!239 = !DISubprogram(name: "log2f", scope: !29, file: !29, line: 774, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!240 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !241, file: !37, line: 1149)
!241 = !DISubprogram(name: "log2l", scope: !29, file: !29, line: 775, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!242 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !243, file: !37, line: 1151)
!243 = !DISubprogram(name: "logb", scope: !29, file: !29, line: 778, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!244 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !245, file: !37, line: 1152)
!245 = !DISubprogram(name: "logbf", scope: !29, file: !29, line: 779, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!246 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !247, file: !37, line: 1153)
!247 = !DISubprogram(name: "logbl", scope: !29, file: !29, line: 780, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!248 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !249, file: !37, line: 1155)
!249 = !DISubprogram(name: "lrint", scope: !29, file: !29, line: 942, type: !250, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!250 = !DISubroutineType(types: !251)
!251 = !{!252, !15}
!252 = !DIBasicType(name: "long int", size: 64, encoding: DW_ATE_signed)
!253 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !254, file: !37, line: 1156)
!254 = !DISubprogram(name: "lrintf", scope: !29, file: !29, line: 943, type: !255, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!255 = !DISubroutineType(types: !256)
!256 = !{!252, !93}
!257 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !258, file: !37, line: 1157)
!258 = !DISubprogram(name: "lrintl", scope: !29, file: !29, line: 944, type: !259, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!259 = !DISubroutineType(types: !260)
!260 = !{!252, !104}
!261 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !262, file: !37, line: 1159)
!262 = !DISubprogram(name: "lround", scope: !29, file: !29, line: 1035, type: !250, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!263 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !264, file: !37, line: 1160)
!264 = !DISubprogram(name: "lroundf", scope: !29, file: !29, line: 1036, type: !255, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!265 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !266, file: !37, line: 1161)
!266 = !DISubprogram(name: "lroundl", scope: !29, file: !29, line: 1037, type: !259, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!267 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !268, file: !37, line: 1163)
!268 = !DISubprogram(name: "nan", scope: !29, file: !29, line: 1087, type: !269, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!269 = !DISubroutineType(types: !270)
!270 = !{!15, !271}
!271 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !272, size: 64)
!272 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !19)
!273 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !274, file: !37, line: 1164)
!274 = !DISubprogram(name: "nanf", scope: !29, file: !29, line: 1088, type: !275, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!275 = !DISubroutineType(types: !276)
!276 = !{!93, !271}
!277 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !278, file: !37, line: 1165)
!278 = !DISubprogram(name: "nanl", scope: !29, file: !29, line: 1089, type: !279, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!279 = !DISubroutineType(types: !280)
!280 = !{!104, !271}
!281 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !282, file: !37, line: 1167)
!282 = !DISubprogram(name: "nearbyint", scope: !29, file: !29, line: 931, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!283 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !284, file: !37, line: 1168)
!284 = !DISubprogram(name: "nearbyintf", scope: !29, file: !29, line: 932, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!285 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !286, file: !37, line: 1169)
!286 = !DISubprogram(name: "nearbyintl", scope: !29, file: !29, line: 933, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!287 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !288, file: !37, line: 1171)
!288 = !DISubprogram(name: "nextafter", scope: !29, file: !29, line: 1098, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!289 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !290, file: !37, line: 1172)
!290 = !DISubprogram(name: "nextafterf", scope: !29, file: !29, line: 1099, type: !127, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!291 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !292, file: !37, line: 1173)
!292 = !DISubprogram(name: "nextafterl", scope: !29, file: !29, line: 1100, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!293 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !294, file: !37, line: 1175)
!294 = !DISubprogram(name: "nexttoward", scope: !29, file: !29, line: 1103, type: !295, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!295 = !DISubroutineType(types: !296)
!296 = !{!15, !15, !104}
!297 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !298, file: !37, line: 1176)
!298 = !DISubprogram(name: "nexttowardf", scope: !29, file: !29, line: 1104, type: !299, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!299 = !DISubroutineType(types: !300)
!300 = !{!93, !93, !104}
!301 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !302, file: !37, line: 1177)
!302 = !DISubprogram(name: "nexttowardl", scope: !29, file: !29, line: 1105, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!303 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !304, file: !37, line: 1179)
!304 = !DISubprogram(name: "remainder", scope: !29, file: !29, line: 1053, type: !44, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!305 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !306, file: !37, line: 1180)
!306 = !DISubprogram(name: "remainderf", scope: !29, file: !29, line: 1054, type: !127, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!307 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !308, file: !37, line: 1181)
!308 = !DISubprogram(name: "remainderl", scope: !29, file: !29, line: 1055, type: !131, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!309 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !310, file: !37, line: 1183)
!310 = !DISubprogram(name: "remquo", scope: !29, file: !29, line: 1058, type: !311, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!311 = !DISubroutineType(types: !312)
!312 = !{!15, !15, !15, !64}
!313 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !314, file: !37, line: 1184)
!314 = !DISubprogram(name: "remquof", scope: !29, file: !29, line: 1059, type: !315, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!315 = !DISubroutineType(types: !316)
!316 = !{!93, !93, !93, !64}
!317 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !318, file: !37, line: 1185)
!318 = !DISubprogram(name: "remquol", scope: !29, file: !29, line: 1060, type: !319, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!319 = !DISubroutineType(types: !320)
!320 = !{!104, !104, !104, !64}
!321 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !322, file: !37, line: 1187)
!322 = !DISubprogram(name: "rint", scope: !29, file: !29, line: 937, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!323 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !324, file: !37, line: 1188)
!324 = !DISubprogram(name: "rintf", scope: !29, file: !29, line: 938, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!325 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !326, file: !37, line: 1189)
!326 = !DISubprogram(name: "rintl", scope: !29, file: !29, line: 939, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!327 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !328, file: !37, line: 1191)
!328 = !DISubprogram(name: "round", scope: !29, file: !29, line: 1030, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!329 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !330, file: !37, line: 1192)
!330 = !DISubprogram(name: "roundf", scope: !29, file: !29, line: 1031, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!331 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !332, file: !37, line: 1193)
!332 = !DISubprogram(name: "roundl", scope: !29, file: !29, line: 1032, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!333 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !334, file: !37, line: 1195)
!334 = !DISubprogram(name: "scalbln", scope: !29, file: !29, line: 871, type: !335, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!335 = !DISubroutineType(types: !336)
!336 = !{!15, !15, !252}
!337 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !338, file: !37, line: 1196)
!338 = !DISubprogram(name: "scalblnf", scope: !29, file: !29, line: 872, type: !339, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!339 = !DISubroutineType(types: !340)
!340 = !{!93, !93, !252}
!341 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !342, file: !37, line: 1197)
!342 = !DISubprogram(name: "scalblnl", scope: !29, file: !29, line: 873, type: !343, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!343 = !DISubroutineType(types: !344)
!344 = !{!104, !104, !252}
!345 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !346, file: !37, line: 1199)
!346 = !DISubprogram(name: "scalbn", scope: !29, file: !29, line: 867, type: !67, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!347 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !348, file: !37, line: 1200)
!348 = !DISubprogram(name: "scalbnf", scope: !29, file: !29, line: 868, type: !349, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!349 = !DISubroutineType(types: !350)
!350 = !{!93, !93, !24}
!351 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !352, file: !37, line: 1201)
!352 = !DISubprogram(name: "scalbnl", scope: !29, file: !29, line: 869, type: !353, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!353 = !DISubroutineType(types: !354)
!354 = !{!104, !104, !24}
!355 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !356, file: !37, line: 1203)
!356 = !DISubprogram(name: "tgamma", scope: !29, file: !29, line: 918, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!357 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !358, file: !37, line: 1204)
!358 = !DISubprogram(name: "tgammaf", scope: !29, file: !29, line: 919, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!359 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !360, file: !37, line: 1205)
!360 = !DISubprogram(name: "tgammal", scope: !29, file: !29, line: 920, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!361 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !362, file: !37, line: 1207)
!362 = !DISubprogram(name: "trunc", scope: !29, file: !29, line: 1044, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!363 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !364, file: !37, line: 1208)
!364 = !DISubprogram(name: "truncf", scope: !29, file: !29, line: 1045, type: !98, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!365 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !366, file: !37, line: 1209)
!366 = !DISubprogram(name: "truncl", scope: !29, file: !29, line: 1046, type: !102, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!367 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !368, file: !371, line: 48)
!368 = !DIDerivedType(tag: DW_TAG_typedef, name: "int8_t", file: !369, line: 35, baseType: !370)
!369 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Cx86_64-w64-mingw32\5Cinclude\5Cstdint.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!370 = !DIBasicType(name: "signed char", size: 8, encoding: DW_ATE_signed_char)
!371 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Clib\5Cgcc\5Cx86_64-w64-mingw32\5C8.3.0\5Cinclude\5Cc++\5Ccstdint", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!372 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !373, file: !371, line: 49)
!373 = !DIDerivedType(tag: DW_TAG_typedef, name: "int16_t", file: !369, line: 37, baseType: !374)
!374 = !DIBasicType(name: "short", size: 16, encoding: DW_ATE_signed)
!375 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !376, file: !371, line: 50)
!376 = !DIDerivedType(tag: DW_TAG_typedef, name: "int32_t", file: !369, line: 39, baseType: !24)
!377 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !378, file: !371, line: 51)
!378 = !DIDerivedType(tag: DW_TAG_typedef, name: "int64_t", file: !369, line: 41, baseType: !215)
!379 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !380, file: !371, line: 53)
!380 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast8_t", file: !369, line: 58, baseType: !370)
!381 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !382, file: !371, line: 54)
!382 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast16_t", file: !369, line: 60, baseType: !374)
!383 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !384, file: !371, line: 55)
!384 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast32_t", file: !369, line: 62, baseType: !24)
!385 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !386, file: !371, line: 56)
!386 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast64_t", file: !369, line: 64, baseType: !215)
!387 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !388, file: !371, line: 58)
!388 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least8_t", file: !369, line: 45, baseType: !370)
!389 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !390, file: !371, line: 59)
!390 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least16_t", file: !369, line: 47, baseType: !374)
!391 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !392, file: !371, line: 60)
!392 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least32_t", file: !369, line: 49, baseType: !24)
!393 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !394, file: !371, line: 61)
!394 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least64_t", file: !369, line: 51, baseType: !215)
!395 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !396, file: !371, line: 63)
!396 = !DIDerivedType(tag: DW_TAG_typedef, name: "intmax_t", file: !369, line: 68, baseType: !215)
!397 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !398, file: !371, line: 64)
!398 = !DIDerivedType(tag: DW_TAG_typedef, name: "intptr_t", file: !399, line: 62, baseType: !252)
!399 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Cx86_64-w64-mingw32\5Cinclude\5Ccrtdefs.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!400 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !401, file: !371, line: 66)
!401 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint8_t", file: !369, line: 36, baseType: !402)
!402 = !DIBasicType(name: "unsigned char", size: 8, encoding: DW_ATE_unsigned_char)
!403 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !404, file: !371, line: 67)
!404 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint16_t", file: !369, line: 38, baseType: !405)
!405 = !DIBasicType(name: "unsigned short", size: 16, encoding: DW_ATE_unsigned)
!406 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !407, file: !371, line: 68)
!407 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint32_t", file: !369, line: 40, baseType: !408)
!408 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!409 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !410, file: !371, line: 69)
!410 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint64_t", file: !369, line: 42, baseType: !411)
!411 = !DIBasicType(name: "long long unsigned int", size: 64, encoding: DW_ATE_unsigned)
!412 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !413, file: !371, line: 71)
!413 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast8_t", file: !369, line: 59, baseType: !402)
!414 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !415, file: !371, line: 72)
!415 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast16_t", file: !369, line: 61, baseType: !405)
!416 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !417, file: !371, line: 73)
!417 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast32_t", file: !369, line: 63, baseType: !408)
!418 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !419, file: !371, line: 74)
!419 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast64_t", file: !369, line: 65, baseType: !411)
!420 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !421, file: !371, line: 76)
!421 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least8_t", file: !369, line: 46, baseType: !402)
!422 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !423, file: !371, line: 77)
!423 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least16_t", file: !369, line: 48, baseType: !405)
!424 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !425, file: !371, line: 78)
!425 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least32_t", file: !369, line: 50, baseType: !408)
!426 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !427, file: !371, line: 79)
!427 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least64_t", file: !369, line: 52, baseType: !411)
!428 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !429, file: !371, line: 81)
!429 = !DIDerivedType(tag: DW_TAG_typedef, name: "uintmax_t", file: !369, line: 69, baseType: !411)
!430 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !431, file: !371, line: 82)
!431 = !DIDerivedType(tag: DW_TAG_typedef, name: "uintptr_t", file: !399, line: 75, baseType: !432)
!432 = !DIBasicType(name: "long unsigned int", size: 64, encoding: DW_ATE_unsigned)
